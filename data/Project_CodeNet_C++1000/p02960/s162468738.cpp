#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;
template <typename A, size_t N, typename T> void Fill(A (&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
// long long mod = 998244353;
#define REP(i, n) for (long long i = 0; i < (n); i++)
#define rep(i, a, n) for (long long i = a; i < (n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
long long mod = 1000000007;
long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t % 13;
    } else {
        return modpow(m, n - 1) * m % 13;
    }
}
long long power(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = pow(m, n / 2);
        return t * t;
    } else {
        return pow(m, n - 1) * m;
    }
}

long long moddiv(long long a, long long b) { return (a * modpow(b, mod - 2)) % mod; }

const ll INF = 1LL << 60;

string change_binary(long long a) {
    string ret;
    for (int i = 31; i >= 0; i--) {
        ret += (a >> i & 1) + '0';
    }
    return ret;
}

ll nCkmod(ll n, ll k) {
    ll denomi = 1;
    for (int i = n; i > n - k; i--) {
        denomi *= i;
        denomi %= mod;
    }
    ll numera = 1;
    REP(i, k) {
        numera *= (i + 1);
        numera %= mod;
    }
    return moddiv(denomi, numera);
}
string s;
ll memo[100001][14];
ll func(ll row, ll m13) {
    if (row == s.size()) {
        if (m13 == 5) {
            return 1;
        } else {
            return 0;
        }
    }
    if (memo[row][m13] != -1) {
        return memo[row][m13];
    }
    if (s[row] != '?') {
        memo[row][m13] = func(row + 1, (m13 + (s[row] - '0') * modpow(10, s.size() - row - 1)) % 13);
        memo[row][m13] %= mod;
        return memo[row][m13];
    }
    ll ret = 0;
    REP(i, 10) {
        ret += func(row + 1, (m13 + i * modpow(10, s.size() - row - 1)) % 13);
        ret %= mod;
    }
    memo[row][m13] = ret;
    ret %= mod;
    return ret;
}
int main() {
    Fill(memo, -1);
    cin >> s;
    cout << func(0, 0) << endl;
}