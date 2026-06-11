#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll y = n / i;
        ans += i * (y + 1) * y / 2;
    }

    cout << ans << endl;
    return 0;
}
