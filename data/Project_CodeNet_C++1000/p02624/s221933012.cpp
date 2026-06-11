#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll n;  cin >> n;
    ll *f = new ll[n+1];
    for (ll i = 0; i < n+1; i++)
        f[i] = 0;

    for (ll i = 1 ;i <= n; i++) {
        for (ll j = i; j <= n; j += i) {
            f[j]++;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (long long)(i * f[i]);
    }

    cout << ans << endl;

    return 0;
}