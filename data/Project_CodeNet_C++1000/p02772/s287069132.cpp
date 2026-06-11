#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    int n;
    cin >> n;
    rep(i, 0, n) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            if (a % 3 == 0 || a % 5 == 0) {
                continue;
            } else {
                cout << "DENIED\n";
                return 0;
            }
        }
    }
    cout << "APPROVED\n";
}
