#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll dp[100010][2];

int main() {
    string s; cin >> s;
    int n = s.size();

    dp[0][0] = 1;
    dp[0][1] = 2;
    for (int i = 1; i < n; i++) {
        int now = s[i] - '0';

        dp[i][0] = 3 * dp[i-1][0];
        dp[i][0] %= MOD;

        if (now == 1) {
            dp[i][0] += dp[i-1][1];
            dp[i][0] %= MOD;
        }

        if (now == 0) {
            dp[i][1] = dp[i-1][1];
        } else {
            dp[i][1] = dp[i-1][1] * 2;
            dp[i][1] %= MOD;
        }
    }

    cout << (dp[n-1][0] + dp[n-1][1]) % MOD << endl;
}
