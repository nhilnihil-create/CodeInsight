#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<string> vs;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> pp;
typedef double ld;
typedef long double lld;
#define INF 0x3f3f3f3f // for int
#define LL_INF 0x3f3f3f3f3f3f3f3f // for ll
#define ms(x, y) memset(x, y, sizeof(x))
//coordinate compression:sort(val.begin(), val.end());
//		val.resize(unique(val.begin(), val.end()) - val.begin());
#define nl '\n'
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const int MOD = 1e9 + 7;

//remember to remove ios stuff if i use scanf

//printf("%05lld\n", x); --> print last 5 digits including 0's
//printf("%02d:%02d", h, m); --> time
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll pwmd(ll b, ll exp) {
    ll ret = 1;
    while (exp > 0) {
        if (exp % 2 == 1) ret = (ret * b) % MOD;
        exp /= 2;
        b = (b * b) % MOD;
    }
    return ret;
}
//void RotateArr(int X) {
//    for (int n=0; n<X; n++) {
//        for (int i=0; i<N/2; i++) {
//            for (int j=0; j<N; j++) {
//                swap(a[i][j], a[N-i-1][j]);
//            }
//        }
//        for (int i=0; i<N; i++) {
//            for (int j=i+1; j<N; j++) {
//                swap(a[i][j], a[j][i]);
//            }
//        }
//    }
//}

/*
 * string input;
 *
 * stringstream ss(input);
 *- if the input contains '\n', separate lines with: string line; while (getline(ss, line))
 * - clear() to clear the stream
 * - >> : read smth from stringstream object ie. while (s >> word)
 */

struct pair_hash { //--> for unordered_set<pair<ll, ll>>
    //initialize the set with unordered_set<pair<ll, ll>, pair_hash>st
    inline std::size_t operator()(const std::pair<ll,ll> & v) const {
        return v.first*31+v.second;
    }
};
/* for dijkstra:
 * bool operator < (const E &other) const {
        return this->w > other.w;
    }
 */

const int MM = 2e5 + 5;
int n; ll pma1 = LL_INF, pma2 = LL_INF; pll p[MM];

void solve(int tc) {

    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll x, y; cin >> x >> y; p[i] = {x, y};
    }
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) {
        ll x = p[i].first, y = p[i].second;
        ans = max(ans, x - y - pma1);
        ans = max(ans, x + y - pma2);
        pma1 = min(pma1, x - y); pma2 = min(pma2, x + y);
    }
    cout << ans << nl;

}

//you should really read the stuff at the bottom

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
*/