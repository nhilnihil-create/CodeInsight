#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    ll n, ans = 1e15;
    cin >> n;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans = min(ans, i + n / i - 2);
        }
    }
    cout << ans << endl;
    return 0;
}