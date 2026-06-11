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
    int N, K;
    cin >> N >> K;
    ll H[N];
    rep(i, N) cin >> H[i];
    map<ll, int> mp;
    mp[0]++;
    rep(i, N) mp[H[i]]++;
    int n = 0;
    for(auto &e: mp){
        e.second = n;
        n++;
    }
    ll h[n];
    h[0] = 0;
    rep(i, N) h[mp[H[i]]] = H[i];
    //i:=どこまで見たか、j:=何回変更したか、k:=右端が何であるか
    ll dp[N+1][K+1][n];
    rep(i, N+1) rep(j, K+1) rep(k, n) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    rep(i, N){
        rep(j, K+1){
            rep(k, n){
                if(dp[i][j][k] == INF) continue;
                int l = mp[H[i]];
                //変更なし
                dp[i+1][j][l] = min(dp[i+1][j][l], dp[i][j][k]+max(0LL, h[l]-h[k]));
                if(j == K) continue;
                //変更あり
                dp[i+1][j+1][k] = min(dp[i+1][j+1][k], dp[i][j][k]);
            }
        }
    }
    ll ans = INF;
    rep(j, K+1) rep(k, n) ans = min(ans, dp[N][j][k]);
    cout << ans << endl;
}