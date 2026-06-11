#include<bits/stdc++.h>
using namespace std;

//a^b % modを求める
int64_t MODpow(int64_t a, int64_t b, int64_t mod) {
    int64_t result = 1;
    while (b) {
        if (b % 2 == 1) {
            result *= a;
            result %= mod;
        }

        b /= 2;
        a *= a;
        a %= mod;
    }

    return result;
}

int main() {
    int64_t N, P;
    string S;
    cin >> N >> P >> S;

    vector<int64_t> A(N);
    for (int64_t i = 0; i < N; i++) {
        A[i] = S[i] - '0';
    }

    int64_t ans = 0;

    if (P == 2 || P == 5) {
        for (int64_t i = 0; i < N; i++) {
            if (A[i] % P == 0) {
                ans += i + 1;
            }
        }
        cout << ans << endl;
        return 0;
    }

    //num[i] := Sのi文字目以降を評価した整数をPで割った余りがiであるような個数
    vector<int64_t> num(P, 0);
    num[0] = 1;

    int64_t u = 0;
    for (int64_t i = N - 1; i >= 0; i--) {
        (u += A[i] * MODpow(10, N - 1 - i, P)) %= P;
        ans += num[u]++;
    }

    cout << ans << endl;
}