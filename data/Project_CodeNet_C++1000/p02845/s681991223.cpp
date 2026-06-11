#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n-1; i > 0; i--)
#define FOR(i, n, m) for(int i = n; i < (int)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()
#define INF (ll)1e18
#define PI 3.14159265358979

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll MOD = 1000000007;

int main()
{
    ll N;
    cin >> N;

    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    vector<vector<ll>> dp(N+1, vector<ll>(3,0));
    REP(i, N) {
        REP(j, 3) {
            if (dp[i][j] == A[i]) {
                dp[i+1][j] = dp[i][j] + 1;
                break;
            }
        }
        REP(j, 3) {
            if (dp[i+1][j] == 0) dp[i+1][j] = dp[i][j];
        }
    }
    ll ans = 1;
    REP(i, N) {
        ll cnt = 0;
        REP(j, 3) {
            if (A[i] == dp[i][j]) {
                cnt++;
            }
        }
        ans *= cnt;
        ans %= MOD;
    }
    PRINT(ans);
    return 0;
}
