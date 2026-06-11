#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <stack>
#include <complex>
#include <functional>
#include <tuple>

using namespace std;

constexpr int inf = 1e9 + 7;
constexpr int mod = 1e9 + 7;

using ll = long long;

ll modpow(ll a, ll n) {
    ll result = 1;
    ll base = a;
    ll mask = 1;
    while (mask <= n) {
        if (n & mask) (result *= base) %= mod;
        mask <<= 1;
        (base *= base) %= mod;
    }
    return result;
}

int main() {

    int n;
    cin >> n;

    ll ans = 0LL;

    ans = modpow(10, n) - modpow(9, n) * 2 + modpow(8, n);

    ans += 10LL * mod;
    ans %= mod;

    cout << ans << endl;

    return 0;
}