#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for(ll i=k; i<=n+1; i++) {
        ll max = i * (2 * n - i + 1) / 2;
        ll min = i * (i - 1) / 2;
        ans += max - min + 1;
    }
    cout << ans % 1000000007 << endl;
}