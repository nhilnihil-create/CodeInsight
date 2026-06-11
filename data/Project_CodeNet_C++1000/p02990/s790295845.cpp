#include <bits/stdc++.h>

using namespace std;

#define MOD (1000000007)

struct ModInt {
    long long x;

    ModInt (long long x = 0):x (x%MOD) {}

    ModInt& operator+=(const ModInt a) {
        if ( (x += a.x) >= MOD )
            x -= MOD;
        return *this;
    }

    ModInt& operator-=(const ModInt a) {
        if ( (x += MOD - a.x) >= MOD )
            x -= MOD;
        return *this;
    }

    ModInt& operator*=(const ModInt a) {
        (x *= a.x) %= MOD;
        return *this;
    }

    ModInt operator+(const ModInt a) {
        ModInt res(*this);
        return res += a;
    }

    ModInt operator-(const ModInt a) {
        ModInt res(*this);
        return res -= a;
    }

    ModInt operator*(const ModInt a) {
        ModInt res(*this);
        return res *= a;
    }
};

ModInt C[4005][4005];
static void init_comb () {
    C[0][0] = 1;
    for ( int i = 0; i <= 4000; i++ ) {
        for ( int j = 0; j <= i; j++ ) {
            C[i+1][j] += C[i][j];
            C[i+1][j+1] += C[i][j];
        }
    }
}

static ModInt calc_comb (int n, int k) {
    return C[n][k];
}

static ModInt f2 (int n, int k) {
    return calc_comb(n+k-1, k-1);
}

static ModInt f (int n, int k) {
    if ( n < k )
        return 0;
    if ( n == 0 && k == 0 )
        return 1;
    if ( k < 1 )
        return 0;
    return f2(n-k, k);
}

int main (void) {
    long long N, K;
    cin >> N >> K;

    init_comb();

    for ( int i = 1; i <= K; i++ ) {
        ModInt blue = f(K, i);
        ModInt red = f2(N-K-(i-1), i+1);
        ModInt ans = blue * red;
        cout << ans.x << endl;
    }

    return 0;
}
