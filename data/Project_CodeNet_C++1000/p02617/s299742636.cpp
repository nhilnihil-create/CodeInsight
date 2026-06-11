#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ll n;  cin >> n;
    ll ans = 0;

    for (ll i = 0; i < n-1; i++) {
        ans += (n-i)*(n-i+1)/2;
        ll u, v;   cin >> u >> v;
        if (u > v)
            swap(u, v);

        ans -= u*(n-v+1);
    }

    ans += 1;

    cout << ans << endl;
    return 0;
}