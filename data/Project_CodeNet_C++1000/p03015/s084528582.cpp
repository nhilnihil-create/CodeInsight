#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;
typedef pair<int, int> P;
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main()
{
    string L;
    cin >> L;

    vector<vector<ll>> dp((int)L.size() + 1, vector<ll>(2, 0));
    dp[0][0] = 1;

    rep(i, L.size()) {
        int num = L[i] - '0';
        rep(j, 2) {
            for (int k = 0; k <= (j ? 1 : num); k++) {
                int s = (k ? 2 : 1);
                dp[i + 1][j || (k < num)] += dp[i][j] * s;
                dp[i + 1][j || (k < num)] %= MOD;
            }
        }
    }

    int len = (int)L.size();
    cout << (dp[len][0] + dp[len][1]) % MOD << endl;
    return 0;
}