/*input
2
1 1
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                int x = a[i], y = a[j], z = a[k];
                if (x == y || y == z || z == x) continue;
                if (abs(x-y) < z && z < x+y) ans++;
            }
        }
    }
    cout << ans << endl;
}