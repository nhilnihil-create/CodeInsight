#include <iostream>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
    if (b > a) return gcd(b, a);
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ll a, b;
    cin >> a >> b;
    int cnt = 1;
    for (ll i = 2; i * i <= min(a, b); i++) {
        if (a % i == 0 && b % i == 0) {
            a /= i;
            b /= i;
            cnt++;
        }
        while (a % i == 0) a /= i;
        while (b % i == 0) b /= i;
    }
    if (gcd(a, b) > 1) cnt++;
    cout << cnt;
}

