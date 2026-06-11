#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    long long N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (long long i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long cntA = 0;
    for (long long i = 0; i < N - 1; i++) {
        for (long long j = i + 1; j < N; j++) {
            if (A[i] > A[j]) {
                cntA++;
            }
        }
    }
    long long cntB = 0;
    for (long long i = 0; i < N; i++) {
        for (long long j = 0; j < N; j++) {
            if (A[j] > A[i]) {
                cntB++;
            }
        }
    }

    cout << ((cntA * K) % MOD + (cntB * ((K * (K - 1) / 2) % MOD))) % MOD << endl;
    return 0;
}
