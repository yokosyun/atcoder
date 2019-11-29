//https://atcoder.jp/contests/abc012/tasks/abc012_4
//ABC012Dバスと避けられない運命

#include <bits/stdc++.h>
using namespace std;
const int IINF = INT_MAX;
#define REP(i, n) for (int i = 0; i < n; i++)

int main() {
int n, m, d[305][305];
cin >> n >> m;
//input
REP(i,n) fill(d[i], d[i]+n, IINF/2);
REP(i,m){
int a, b, t;
cin >> a >> b >> t;
a--;
b--;
d[a][b] = t;
d[b][a] = t;
}

//calc
REP(k,n)REP(i,n)REP(j,n) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);//forのkを内側に入れても回る
int ans = IINF;

//searching for minmum time to company in worst case
REP(i,n){
int tmp = 0;
    REP(j,n){
    if(i==j)continue;
    tmp = max(tmp, d[i][j]);
    }
ans = min(ans, tmp);
}

cout << ans << endl;
return 0;
}
