#include <bits/stdc++.h>

using namespace std;

int main () {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N), B(M), preA(N+1), preB(M+1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        preA[i+1] += A[i] + preA[i];
        // cout << preA[i+1] << " ";
    }
    // cout << endl;
    for (int i = 0; i < M; i++) {
        cin >> B[i];
        preB[i+1] += B[i] + preB[i];
        // cout << preB[i+1] << " ";
    }
    int res = 0;
    int posB = M;
    for (int i = 0; i <= N; i++) {
        int lenB = K - preA[i];
        if (lenB < 0) break;
        while (posB >= 0 && preB[posB] > lenB) {
            posB--;
        }
        // cout <<i << " " << posB << endl;
        res = max(res, posB+i);
    }
    cout << res << endl;
}
