#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using vi = vector<int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

const int MOD = 1000000007;
const int INF = 1 << 30;

lint log_mul(lint base, lint bit) {
    lint res = 0;

    while (bit) {
        if (bit & 1) res = (res + base) % MOD;
        base = (base + base) % MOD;
        bit >>= 1;
    }

    return res;
}

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    int N, K;
    cin >> N >> K;
    vi A(N), F(N, 0), C(N, 0);
    rep(i, N) cin >> A[i];

    rep(i, N) {
        int cl = A[i];
        rep(j, N) {
            if (i == j) continue;

            if (cl > A[j]) {
                if (j < i) F[i]++;
                C[i]++;
            }
        }
    }

    lint res = 0;

    rep(i, N) {
        lint p = log_mul(K, K+1);
        p = log_mul(p, C[i]);
        lint inv = modpow(2, MOD-2);
        res += p * inv;
        res %= MOD;
        res -= log_mul(K, F[i]);
        if (res < 0) res += MOD;
        res %= MOD;
    }

    cout << res << endl;
    return 0;
}
