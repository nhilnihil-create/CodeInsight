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
    int a[M], b[M], c[M];
    rep(i, M){
        cin >> a[i] >> b[i];
        c[i] = 0;
        rep(j, b[i]){
            int C; cin >> C;
            c[i] |= 1<<(C-1);
        }
    }
    int dp[1<<N];
    fill(dp, dp+(1<<N), inf);
    dp[0] = 0;
    rep(i, M){
        rep3(j, (1<<N)-1, 0){
            dp[j|c[i]] = min(dp[j|c[i]], dp[j]+a[i]);
        }
    }
    if(dp[(1<<N)-1] == inf) cout << -1 << endl;
    else cout << dp[(1<<N)-1] << endl;
}