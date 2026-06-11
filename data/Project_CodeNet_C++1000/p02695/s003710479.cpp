#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define REP(i, x, y) for(ll i = (ll)x; i < (ll)y; i++)

ll a[55], b[55], c[55], d[55];
ll N, M, Q;
ll nums[11];
ll ans = 0;

void solve(ll dep, ll now) {
    if (dep < N) {
        REP(i, now, M + 1) {
            nums[dep] = i;
            solve(dep + 1, i);
        }
    } else {
        ll tmp = 0;
        REP(i, 0, Q) {
            if (nums[b[i]] - nums[a[i]] == c[i]) {
                tmp += d[i];
            }
        }
        ans = max(ans, tmp);
    }
}
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> Q;
    REP(i, 0, Q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
    }
    solve(0, 1);
    cout << ans << endl;
}