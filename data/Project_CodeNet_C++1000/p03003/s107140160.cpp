#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    int N, M;
    cin >> N >> M;
    int S[N], T[M];
    rep(i, N) cin >> S[i];
    rep(i, M) cin >> T[i];
    //dp[i][j]:=S[0,i)とT[0,j)の共通部分列の数
    ll dp[N+1][M+1];
    rep(i, N+1) dp[i][0] = 1;
    rep(j, M+1) dp[0][j] = 1;
    rep2(i, 1, N){
        rep2(j, 1, M){
            if(S[i-1] == T[j-1]){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
            else{
                dp[i][j] = dp[i-1][j]+dp[i][j-1]+MOD-dp[i-1][j-1];
            }
            dp[i][j] %= MOD;
        }
    }
    cout << dp[N][M] << endl;
}