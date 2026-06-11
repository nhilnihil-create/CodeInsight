#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define imfor(i, n) for(int i = 0; i < n; i++)
using namespace std;
ll MOD = 1000000007;

ll calc(ll a, ll b, ll p) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        ll d = calc(a, b / 2, p);
        return (d * d) % p;
    }
    else {
        return (a * calc(a, b - 1, p) % p);
    }
}

int main() {
    ll x, y;
    cin >> x >> y;

    if ((x + y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    ll n = ((2 * y) - x) / 3;
    ll m = ((2 * x) - y) / 3;

    if (n < 0 || m < 0) {
        cout << 0 << endl;
        return 0;
    }

    n = n + m;

    long long fact[n]; // n
    fact[0] = 1;
    for (int i = 1; i <= n; i++) { // n
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    ll ans = (((fact[n] * calc(fact[n - m], MOD - 2, MOD)) % MOD) * calc(fact[m], MOD - 2, MOD)) % MOD;
    cout << ans << endl;
}