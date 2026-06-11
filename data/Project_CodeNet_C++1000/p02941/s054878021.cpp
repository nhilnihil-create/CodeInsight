#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define fst first
#define sc second
#define snd second
#define sz(X) (int)(X).size()
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fornr(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for(int i = int(a); i < int(b); i++)
#define all(X) X.begin(), X.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef vector<int> vi;

const int N = 1e6;
const int LOG = 21;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LLMOD = 998244353;
const ll LLINF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vi a(n), b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    set<pii> q;
    forn(i, n) q.insert({b[i], i});
    ll ans = 0;
    while (!q.empty()) {
        int i = q.rbegin()->second;
        q.erase(*q.rbegin());
        int neighbors = b[(i + n - 1) % n] + b[(i + 1) % n];
        int d = b[i] - a[i];
        if (d % neighbors == 0) {
            ans += d / neighbors;
            b[i] = a[i];
        } else {
            if (neighbors >= b[i]) {
                cout << "-1\n";
                return 0;
            }
            ans += b[i] / neighbors;
            b[i] %= neighbors;
            if (b[i] < a[i]) {
                cout << "-1\n";
                return 0;
            }
            q.insert({b[i], i});
        }
    }
    cout << ans << "\n";
    return 0;
}