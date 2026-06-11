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
    VI a(n + 1), b(n);
    REP(i, n + 1) cin >> a[i];
    REP(i, n) cin >> b[i];

    ll ans = 0;
    REP(i, n) {
        ans += min(a[i], b[i]);
        if (a[i] < b[i]) {
            int cnt = min(a[i + 1], b[i] - a[i]);
            a[i + 1] -= cnt;
            ans += cnt;
        }
    }

    cout << ans << ln;
    return 0;
}
