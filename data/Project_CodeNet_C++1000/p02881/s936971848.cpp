#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll ans = n - 1;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0)
        {
            ll j = n / i;
            ans = min(ans, i + j - 2);
        }
    }
    cout << ans << endl;
}