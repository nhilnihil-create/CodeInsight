#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7; // have to be a prime

long long mul(long long a , long long b) {
    return a * b % MOD;
}

long long power(long long a , long long b) {
    if (!b) return 1;
    long long r = power(a , b / 2);
    r = mul(r , r);
    if (b&1) return mul(r , a);
    return r;
}

long long mod_inv(long long x) {
    return power(x , MOD - 2);
}

long long nCr(int n, int r) {
    long long ret = 1;
    r = max(r , n - r);
    for (int i = 1; i <= n - r; ++i) {
        ret = mul(ret , r + i);
        ret = mul(ret , mod_inv(i));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n , k;
    cin >> n >> k;

    int blue = k , red = n - k;

    for (int i = 1 ;i <= k ;i++) {
        if (i > red + 1) {
            cout << 0 << '\n';
            continue;
        }

        int boxes = i;
        int balls = blue;
        int ways = nCr(balls - 1 , boxes - 1);

        boxes = i + 1;
        balls = red - i + 1;

        if (balls)
            ways = mul(ways , nCr(balls - 1 + boxes , boxes - 1));

        cout << ways << '\n';
    }
}
