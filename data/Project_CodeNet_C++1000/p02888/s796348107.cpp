#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    ll ans = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            int safe = lower_bound(a.begin(), a.end(), a[i] + a[j]) - a.begin();
            ans += max(safe - j - 1, 0);
        }
    }
    cout << ans << endl;
}
