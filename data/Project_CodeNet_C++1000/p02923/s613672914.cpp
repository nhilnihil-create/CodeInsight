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
    VI h(n);
    REP(i, n) cin >> h[i];

    int ans = 0;
    int move_count = 0;
    REP(i, n - 1) {
        if (h[i] >= h[i + 1]) {
            move_count++;
        } else {
            ans = max(ans, move_count);
            move_count = 0;
        }
    }
    ans = max(ans, move_count);
    cout << ans << ln;
    return 0;
}
