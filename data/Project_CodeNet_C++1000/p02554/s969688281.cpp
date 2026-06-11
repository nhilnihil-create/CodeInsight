#include <iostream>
#include <string>
using namespace std;
using ll = long long;

ll pow(ll b, ll p, ll m) {
    b = b%m;
    ll ans = 1;
    while(p) {
        if(p & 1) {
            ans = (ans*b)%m;
        }
        p >>= 1;
        b = (b*b)%m;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    const ll m = 1e9+7;

    ans += pow(10, n, m);
    ans %= m;
    ans += pow(8, n, m);
    ans %= m;
    ans -= 2*pow(9, n, m);
    ans %= m;

    while(ans < 0) {
        ans += m;
    }
    cout << ans << '\n';
    return 0;
}