#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int MOD = 1e9 + 7;

int mpow(ll a, int b) {
    int ans = 1;
    while (b) {
        if (b % 2 == 1)
            ans = (ans * a) % MOD;
        b /= 2;
        a = (a * a) % MOD;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;

    cout << ((mpow(10, n) - mpow(9, n) - mpow(9, n) + mpow(8, n)) % MOD + MOD) % MOD << endl;

    return 0;
}