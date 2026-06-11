#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

#define int long long

using namespace std;

const int MOD = 1e9 + 7;

int N, K;

void experiment() {
    static int digits[100001] = { };
    for (int i = 0; i < N; i++) {
        digits[i] = 1;
    }

    static int histogram[100001] = { };

    while (true) {
        // Histogram.
        int gcd = digits[0];
        for (int i = 1; i < N; i++) {
            gcd = __gcd(gcd, digits[i]);
        }
        histogram[gcd]++;
 
        // Exit condition.
        bool flag = true;
        for (int i = 0; i < N; i++) {
            if (digits[i] != K) {
                flag = false;
                break;
            }
        }
        if (flag) {
            break;
        }
 
        // Add one.
        digits[0] += 1;
        for (int i = 0; i < N; i++) {
            if (digits[i] == K + 1) {
                digits[i] = 1;
                digits[i + 1]++;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= K; i++) {
        cerr << i << ": " << histogram[i] << endl;
        ans += i * histogram[i];
    }
    cerr << "ans: " << ans << endl;
}

int power(int x, int y) {
    if (y == 1) {
        return x;
    }

    int t = power(x, y / 2);
    if (y % 2 == 0) {
        return (t * t) % MOD;
    } else {
        return (((t * t) % MOD) * x) % MOD;
    }
}

signed main() {
    cin >> N >> K;

    // experiment();

    int ans = 0;
    static int f[100001] = { };
    for (int i = K; i >= 1; i--) {
        f[i] = power(K / i, N);
        for (int j = 2; i * j <= K; j++) {
            f[i] = (f[i] + MOD - f[i * j]) % MOD;
        }       
        ans = (ans + (i * f[i]) % MOD) % MOD;
    }

    cout << ans << endl;

    return 0;
}