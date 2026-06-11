#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0;i<n;i++) cin >> arr[i];
    if (n <= 0 || n == 1) {
        cout << "0\n";
        return 0;
    }
    if (n == 2) {
        cout << max(arr[0], arr[1]) << "\n";
        return 0;
    }
    sort(arr.begin(), arr.end());
    int cnt = 2;
    ll ans = arr.back();
    for (int i=n-2;i>=0;i--) {
        ans += (2*arr[i]);
        cnt += 2;
        if (cnt == n) {
            cout << ans << "\n";
            break;
        } else if (cnt == n+1) {
            cout << ans - arr[i] << "\n";
            break;
        }
    }
}
