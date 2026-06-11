#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#include <time.h>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
typedef vector<ll> vll;
typedef vector< vector<ll> > matrix;
#define REP(i, x, y) for(ll i = (ll)x; i < (ll)y; i++)
#define DREP(i, x, y, d) for(ll i = (ll)x; i < (ll)y; i += (ll)d)
#define PER(i, x, y) for(ll i = (ll)x; i > (ll)y; i--)
#define DPER(i, x, y, d) for(ll i = (ll)x; i > (ll)y; i -= (ll)d)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-12;

ll modadd(ll x, ll y) {
    return ((x + y) % mod + mod) % mod;
}

ll modminus(ll x, ll y) {
    return (x - y + mod) % mod;
}

ll multiply(ll x, ll y) {
    return (x % mod) * (y % mod) % mod;
}

ll dp[2010][2010];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    ll S[N];
    ll T[M];
    REP(i, 0, N) {
        cin >> S[i];
    }
    REP(i, 0, M) {
        cin >> T[i];
    }
    fill(dp[0], dp[0] + M + 1, 1);
    REP(i, 1, N + 1) {
        dp[i][0] = 1;
        REP(j, 1, M + 1) {
            dp[i][j] = modadd(dp[i][j - 1], modminus(dp[i - 1][j], dp[i - 1][j - 1]));
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = modadd(dp[i][j], dp[i - 1][j - 1]);
            }
        }
    }
    // REP(i, 0, N + 1) {
    //     REP(j, 0, M + 1) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    ll ans = dp[N][M];
    cout << ans << endl;
}
