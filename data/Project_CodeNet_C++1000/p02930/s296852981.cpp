#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N;
int ans[500][500];
//---------------------------------------------------------------------------------------------------
void dfs(int l, int r, int level) {
    if(l + 1 == r) return;
    int c = (l + r) / 2;

    rep(x, l, c) rep(y, c, r) ans[x][y] = ans[y][x] = level;

    dfs(l, c, level + 1);
    dfs(c, r, level + 1);
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    dfs(0, N, 1);

    rep(i, 0, N) {
        rep(j, i + 1, N) {
            if(j != i + 1) printf(" ");
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
}





