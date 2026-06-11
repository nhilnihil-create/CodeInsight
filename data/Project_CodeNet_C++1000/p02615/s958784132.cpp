#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n);

    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += a[(n-1) - i/2];
    }
    cout << ans << endl;
}
