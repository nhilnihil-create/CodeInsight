#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll n) {
    return n * (n + 1) / 2;
}

int main() {
    ll N, K;
    cin >> N >> K;
    ll mod = pow(10, 9) + 7;
    ll sum = 0;
    for (ll i = K; i <= N + 1; i++) {
        sum += f(N + 1) - f(N + 1 - i) - f(i) + 1;
        sum %= mod;
    }
    cout << sum << "\n";
    return 0;
}