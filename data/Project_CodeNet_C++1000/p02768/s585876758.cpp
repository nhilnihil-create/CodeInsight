#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x

#define P (1'000'000'007)

inline int fast_pow(int x, int n, int mod) {
    long long signed res = 1;
    long long accumulation = x;
    for (int i = 0; n >> i > 0; ++ i) {
        if ((n >> i) % 2) {
            res *= accumulation;
            res %= mod;
        }
        accumulation *= accumulation;
        accumulation %= mod;
    }

    return res;
}

inline int fast_comb(int n, int r, int mod) {
    long long a = 1;
    long long b = 1;
    for (int i = 0; i < r; ++i) {
        a = a * (n - i) % mod;
        b = b * (i + 1) % mod;
    }

    b = fast_pow(b, mod - 2, mod);
    return a * b % mod;
}

template<int MOD=P>
struct Mod {
public:
    long long signed value;

    Mod(long long signed val): value(val % MOD) {
        if (value < 0) value += MOD;
    }

    constexpr Mod& operator+=(const Mod& other) noexcept { 
        value += other.value;
        value %= MOD;
        return *this;
    }
    constexpr Mod& operator-=(const Mod& other) noexcept {
        value -= other.value;
        if (value < 0) value += MOD;
        return *this;
    }
    constexpr Mod& operator*=(const Mod& other) noexcept {
        value *= other.value;
        value %= MOD;
        return *this;
    }

    constexpr Mod operator-() noexcept {
         return value == 0 ? 0 : MOD - value;
    }

    constexpr Mod operator+(const Mod& other) const noexcept { return Mod(*this) += other; }
    constexpr Mod operator-(const Mod& other) const noexcept { return Mod(*this) -= other; }
    constexpr Mod operator*(const Mod& other) const noexcept { return Mod(*this) *= other; }
    constexpr bool operator==(const Mod& other) const noexcept { return this->value == other.value; }
    constexpr bool operator!=(const Mod& other) const noexcept { return this->value != other.value; }
};

signed main() {
    int n, a, b;
    cin >> n >> a >> b;

    auto ans = Mod(fast_pow(2, n, P) - 1);
    ans -= fast_comb(n, a, P);
    ans -= fast_comb(n, b, P);
    cout << ans.value;

    return 0;
}