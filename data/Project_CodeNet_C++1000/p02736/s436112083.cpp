/* be name khoda */

// #define long_enable
#include <iostream>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <vector>
#include <fstream>
#include <set>
#include <map>
using namespace std;

#ifdef long_enable
typedef long long int ll;
#else
typedef int ll;
#endif

typedef pair<ll, ll> pii;
typedef pair<pii, ll> ppi;
typedef pair<ll, pii> pip;
typedef vector<ll> vi;
typedef vector<pii> vpii;

#define forifrom(i, s, n) for (ll i = s; i < n; ++i)
#define forirto(i, n, e) for (ll i = (n) - 1; i >= e; --i)
#define fori(i, n) forifrom (i, 0, n)
#define forir(i, n) forirto (i, n, 0)

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define smin(a, b) a = min(a, (b))
#define smax(a, b) a = max(a, (b))

#define debug(x) cout << #x << " -> " << (x) << endl
#define debug2(x, y) cout << #x << ' ' << #y << " -> " << (x) << ' ' << (y) << endl
#define debug3(x, y, z) cout << #x << ' ' << #y << ' ' << #z << " -> " << (x) << ' ' << (y) << ' ' << (z) << endl
#define debug4(x, y, z, t) cout << #x << ' ' << #y << ' ' << #z << ' ' << #t << " -> " << (x) << ' ' << (y) << ' ' << (z) << ' ' << (t) << endl
#define debugp(x) cout << #x << " -> " << "(" << (x).F << ", " << (x).S << ")" << endl
#define debuga(x, n) cout << #x << " -> "; fori (i1_da, n) { cout << (x)[i1_da] << ' '; } cout << endl
#define debugap(x, n) cout << #x << " ->\n"; fori (i1_dap, n) { cout << "(" << (x)[i1_dap].F << ", " << (x)[i1_dap].S << ")\n"; } cout << endl
#define debugaa(x, n, m) cout << #x << " ->\n"; fori (i1_daa, n) { fori (i2_daa, m) { cout << (x)[i1_daa][i2_daa] << ' '; } cout << '\n'; } cout << endl
#define debugav(x, n) cout << #x << " ->\n"; fori (i1_dav, n) { fori (i2_dav, (x)[i1_dav].size()) { cout << (x)[i1_dav][i2_dav] << ' '; } cout << '\n'; } cout << endl
#define debugia(x, n) cout << #x << " ->\n"; fori (i1_dia, n) { cout << i1_dia << " : " << (x)[i1_dia] << '\n'; } cout << endl

const ll MOD = 1000000007;
const ll INF = 2000000000;
const long long BIG = 1446803456761533460LL;

#define Add(a, b) a = ((a) + (b)) % MOD
#define Mul(a, b) a = (1LL * (a) * (b)) % MOD

// -----------------------------------------------------------------------

const ll maxn = 1000010;
const ll maxnlg = 20;

ll n;
ll two[maxn], ar[maxn];
string S;

ll parity(ll a, ll b) {
    return two[b] == two[a] + two[b - a];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    forifrom (i, 1, maxn) {
        two[i] = two[i - 1] + __builtin_ctz(i);
    }
    cin >> n >> S;
    ll c1 = 0;
    fori (i, n) {
        ar[i] = S[i] - '1';
        c1 += ar[i] == 1;
    }
    if (c1) {
        fori (i, n) if (ar[i] == 2) ar[i] = 0;
    } else {
        fori (i, n) if (ar[i] == 2) ar[i] = 1;
    }
    ll ans = 0;
    fori (i, n) {
        ans ^= ar[i] && parity(i, n - 1);
    }
    if (c1 == 0) ans <<= 1;
    cout << ans << '\n';

}
