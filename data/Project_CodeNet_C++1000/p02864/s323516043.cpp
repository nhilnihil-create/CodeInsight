//
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P>IP;
typedef vector<ll> V;
typedef vector<V> V2;
typedef vector<vector<P> > G;
void g_dir(G &graph, ll a, ll b, ll w = 1){graph[a].push_back(P(b, w));}
void g_undir(G &graph, ll a, ll b, ll w = 1){g_dir(graph, a, b, w);g_dir(graph, b, a, w);}
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}
const ll INF = 1145141919810893;
const ll MOD = 1000000007;
const ll NUM = 101010;
void chadd(ll &a, const ll &b){a = (a + b) % MOD;}


int main(){

    ll N, K;
    cin >> N >> K;
    ll H[333];
    rep1(i, N)cin >> H[i];
    ll dp[333][333] = {};
    rep(i, 333)rep(j, 333)dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i, N + 1)rep(j, K + 1)if(dp[i][j] < INF){
        for(ll k = i + 1; k <= N + 1; k++){
            ll c = max(0LL, H[k] - H[i]);
            ll t = k - i - 1;
            chmin(dp[k][j + t], dp[i][j] + c);
        }
    }
    ll ans = INF;
    for(ll k = 0; k <= K; k++)chmin(ans, dp[N + 1][k]);
    cout << ans << endl;


    return 0;
}