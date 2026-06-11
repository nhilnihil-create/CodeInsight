#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int64_t> A(N), B(N);
    for(int i = 0; i < N; ++i) cin >> A[i] >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int l = N / 2 - 1, r = l + 1;
    if(N % 2 == 0) {
        for(int i = 0; i < N; ++i) {
            A[i] *= 2, B[i] *= 2;
        }
        int64_t mn = (A[l] + A[r]) / 2;
        int64_t mx = (B[l] + B[r]) / 2;
        cout << mx - mn + 1 << '\n';
    } else {
        int64_t m = (N + 1) / 2 - 1;
        cout << B[m] - A[m] + 1 << '\n';
    }
    return 0;
}
