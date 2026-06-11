#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;

signed main() {
    int t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    if (t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2) {
        cout << "infinity\n";
        return 0;
    }
    int ans = 0;
    int la = a1 * t1 + a2 * t2, lb = b1 * t1 + b2 * t2;
    if (a1 < b1) {
        if (la > lb) {
            int sum = (b1 - a1) * t1 / (la - lb);
            if ((la - lb) * sum < (b1 - a1) * t1) {
                ans += sum * 2 + 1;
            } else {
                ans += sum * 2;
            }
        } else {
            ans = 0;
        }
    } else {
        if (la < lb) {
            int sum = (a1 - b1) * t1 / (lb - la);
            if ((lb - la) * sum < (a1 - b1) * t1) {
                ans += sum * 2 + 1;
            } else {
                ans += 2 * sum;
            }
        } else {
            ans = 0;
        }
    }
    cout << ans << "\n";
}