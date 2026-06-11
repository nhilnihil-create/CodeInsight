#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());


    ll ans = 0;
    // Iter through all pairs
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            ll ub = lower_bound(arr.begin(), arr.end(), arr[j] + arr[i]) - arr.begin();
//            cout << "pos for pair " << arr[i] << ", " << arr[j] << \
//            " = " << ub << endl;
            ans = ans + (ll) ub - j - 1;
        }
    }

    cout << ans << endl;
}