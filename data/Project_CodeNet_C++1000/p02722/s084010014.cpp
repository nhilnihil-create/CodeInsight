#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;

    int64_t ans = 0;

    //N = (a * K + 1) * K ^ b (a >= 0, b >= 0)の形なら最終的に1になる
    //(1)b = 0のとき
    //N = a * K + 1
    //つまりN - 1の約数の個数
    for (int64_t i = 1; i * i <= N - 1; i++) {
        if ((N - 1) % i != 0) {
            continue;
        }

        //K = i
        if (i != 1) {
            ans++;
        }

        //K = (N - 1) / i
        if ((N - 1) / i != i) {
            ans++;
        }
    }

    //(2)b = 1のとき
    //N = (a * K + 1) * K
    auto ok1 = [&](int64_t K) {
        if (K == 1 || N % K != 0) {
            return false;
        }
        return (N / K - 1) % K == 0;
    };

    for (int64_t i = 1; i * i <= N; i++) {
        if (N % i != 0) {
            continue;
        }

        if (ok1(i)) {
            ans++;
        }
        if (N / i != i && ok1(N / i)) {
            ans++;
        }
    }

    //(2)b >= 2のとき
    //Kの2乗で増えていくので全探索できる
    for (int64_t b = 2; pow(2, b) <= N; b++) {
        for (int64_t K = 2; ; K++) {
            int64_t K_pow_b = pow(K, b);
            if (K_pow_b > N) {
                break;
            }
            if (N % K_pow_b == 0 && (N / K_pow_b - 1) % K == 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}