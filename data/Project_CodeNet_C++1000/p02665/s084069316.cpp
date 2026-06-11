#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N + 1);
    for (int i = 0; i <= N; ++i) {
        cin >> A[i];
    }
    vector<long long> L(N + 1), U(N + 1);
    L[N] = U[N] = A[N];
    for (int i = N - 1; i >= 0; --i) {
        L[i] = (L[i + 1] + 1) / 2 + A[i];
        U[i] = U[i + 1] + A[i];
    }
    if (L[0] > 1) {
        cout << -1 << endl;
        return 0;
    }
    U[0] = 1;
    for (int i = 1; i <= N; ++i) {
        U[i] = min(U[i], (U[i - 1] - A[i - 1]) * 2);
    }
    long long res = 0;
    for (long long p : U) res += p;
    cout << res << endl;
    return 0;
}