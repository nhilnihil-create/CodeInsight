#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans;
    if ((b - a) % 2 == 0)
        ans = (b - a) / 2;
    else
        ans = min(a - 1, n - b) + 1 + (b - a - 1) / 2;

    cout << ans << endl;
    return 0;
}
