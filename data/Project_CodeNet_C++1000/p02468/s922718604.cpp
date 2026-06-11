#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const ll MOD = ll(1e9 + 7);

ll solve(const ll m, const ll n) {
    if (m == 0) return 0;
    if (n == 0) return 1;

    ll ans = 1;
    if (n % 2 != 0) {
        ans = m;
    }

    ll x = solve(m, n / 2);
    return (ans * ((x * x) % MOD)) % MOD;
}

int main(void) {
    int m, n;
    cin >> m >> n;

    cout << solve(m, n) << endl;

    return 0;
}

