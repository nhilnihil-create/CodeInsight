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
#define forabr(i, a, b) for(int i = int(b)-1; i >= int(a); i--)
#define all(X) X.begin(), X.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef vector<int> vi;

const int N = 310;
const ll INF = 1e18;
ll dp[N][N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    n++;
    vector<ll> a(n + 1);
    forab(i, 1, n) cin >> a[i];
    forn(i, N) forn(j, N) forn(l, N) dp[i][j][l] = INF;
    dp[1][0][0] = 0;
    forab(i, 1, n) {
        forn(j, k + 1) {
            forn(l, i) {
                dp[i + 1][j][i] = min(dp[i + 1][j][i], dp[i][j][l] + max(a[i] - a[l], 0ll));
                if (j < k) {
                    dp[i + 1][j + 1][l] = min(dp[i + 1][j + 1][l], dp[i][j][l]);
                }
            }
        }
    }
    ll ans = INF;
    forn(j, k + 1) forn(l, n) ans = min(ans, dp[n][j][l]);
    cout << ans << "\n";
    return 0;
}