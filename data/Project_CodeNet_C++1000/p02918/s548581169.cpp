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
long long mod = 998244353;
#define REP(i, n) for (long long i = 0; i < (n); i++)

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t;
    } else {
        return modpow(m, n - 1) * m;
    }
}

long long moddiv(long long a, long long b) { return (a * modpow(b, mod - 2)) % mod; }

long long nCkmod(long long n, long long k) {
    long long denomi = 1;
    REP(i, n) {
        denomi *= (i + 1);
        denomi %= mod;
    }
    long long numera = 1;
    for (int i = n - k; i > 0; i--) {
        numera *= i;
        numera %= mod;
    }
    REP(i, k) {
        numera *= (i + 1);
        numera %= mod;
    }
    return moddiv(denomi, numera);
}

void print_binary(long long a) {
    for (int i = 31; i >= 0; i--) {
        cout << (a >> i & 1);
    }
    cout << endl;
}
double memo[101][61][50][50];
signed main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    char want = s[0];
    char now = s[0];
    int cnt = 0;
    REP(i, n) {
        if (s[i] != now && s[i] != want) {
            k--;
        }
        now = s[i];
        if (s[i] != want && k >= 0) {
            if (s[i] == 'L') {
                s[i] = 'R';
            } else if (s[i] == 'R') {
                s[i] = 'L';
            }
            //cout << s << endl;
        }
    }
    int unhappy = 0;
    REP(i, n - 1) {
        if (s[i] == 'R' && s[i + 1] == 'L') {
            unhappy += 2;
        }
    }
    if (s[0] == 'L') {
        unhappy++;
    }
    if (s[n - 1] == 'R') {
        unhappy++;
    }
    cout << n - unhappy << endl;
}