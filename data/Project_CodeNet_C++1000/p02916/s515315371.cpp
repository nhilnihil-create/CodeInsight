#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int)(b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (int)(b); --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> VP;
typedef vector<PL> VPL;
typedef vector<string> VS;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    VI a(n), b(n), c(n - 1);
    REP(i, n) {
        cin >> a[i];
        a[i]--;
    }
    REP(i, n) cin >> b[i];
    REP(i, n - 1) cin >> c[i];

    int ans = 0;
    REP(i, n) ans += b[a[i]];
    REP(i, n - 1) {
        if (a[i + 1] == a[i] + 1) ans += c[a[i]];
    }
    cout << ans << ln;
    return 0;
}
