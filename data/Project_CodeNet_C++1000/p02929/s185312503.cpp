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

const int N = 5e2;
const int LOG = 61;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int D = 700;
const ll LLMOD = 1e9 + 7;
const ll LLINF = 1e18;

void mult(ll &a, ll b) {
    a = (a * b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 1;
    vi dp(2 * n);
    forn(i, 2 * n) {
        if (!i) dp[i] = (s[i] == 'W');
        else dp[i] = (s[i] == s[i - 1]);

    }
    ll cnt = 0;
    forn(i, 2 * n) {
        if (dp[i]) {
            if (!cnt) {
                cout << "0\n";
                return 0;
            } else {
                mult(ans, cnt);
                cnt--;
                if (i + 1 < 2 * n) dp[i + 1] ^= 1;
            }
        } else {
            cnt++;
        }
    }
    if (cnt) ans = 0;
    forn(i, n) mult(ans, i + 1);
    cout << ans << "\n";
    return 0;
}
