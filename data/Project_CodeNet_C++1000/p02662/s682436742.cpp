#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(), (X).end()
#define REP(i,x,y) for(ll i = x;i <= y;++i)
vector<string> vec_splitter(string s) {
    for(char& c: s) c = c == ','?  ' ': c;
    stringstream ss; ss << s;
    vector<string> res;
    for(string z; ss >> z; res.push_back(z))
        ;
    return res;
}
void debug_out(vector<string> args, int idx) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, Head H, Tail... T) {
    if(idx > 0) cerr << ", ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __VA_ARGS__)
void localTest() {
    #ifndef ONLINE_JUDGE
        freopen("inp", "r", stdin);
        freopen("out", "w", stdout);
    #endif      
}
const ll N = 3e3 + 5, MOD = 998244353;
ll dp[N][N], A[N], ans[N][N];
ll power(ll a, ll b, ll c) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % c;
        a = (a * a) % c;
        b >>= 1LL;
    }
    return ret;
}
int main() {

    localTest();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, s;
    cin >> n >> s;
    for(ll i = 1;i <= n;++i) cin >> A[i];
    dp[0][0] = 1;
    for(ll i = 1;i <= n;++i) {
        for(ll j = 0;j <= s;++j) {
            dp[i][j] = 2 * dp[i - 1][j];
            if(j - A[i] >= 0) dp[i][j] += dp[i - 1][j - A[i]];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][s] << "\n";
    
    return 0;
}