#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll mod = 1000000000 + 7;

int main(void)
{
    ll N;

    cin >> N;

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll t = 1;
    for (int i = 1; i <= N; i++) {
        t *= 10;
        t %= mod;
    }
    ll n = 1;
    for (int i = 1; i <= N; i++) {
        n *= 9;
        n %= mod;
    }
    ll e = 1;
    for (int i = 1; i <= N; i++) {
        e *= 8;
        e %= mod;
    }
    ll ans = (t - n - n + e) % mod;
    if (ans < 0) {
        ans += mod;
    }
    cout << ans % mod<< endl;

    return 0;
}