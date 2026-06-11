#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n, 0); int64_t ans = 0;
    for (auto i = 0; i < n; i++) cin >> a[i], ans += a[i];
    for (auto i = 1; i < n; i += 2) ans -= 2 * a[i];
    cout << ans << " ";
    for (auto i = 1; i < n; i++) ans = 2 * a[i - 1] - ans, cout << ans << " ";
    cout << endl;
    return 0;
}