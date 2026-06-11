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
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using vi = vector<int>;

#define P (1'000'000'007)

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

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
    int n, k;
    cin >> n >> k;

    Mod ans(0);

    int vc[100001] = {0};

    rep(i, k) {
        int x = k - i;
        int p = fast_pow(k / x, n, P);
        for (int i = x * 2; i <= k; i += x) {
            p -= vc[i];
        }
        vc[x] = p;
        ans += x * p;
    }

    cout << ans.value;

    return 0;
}
