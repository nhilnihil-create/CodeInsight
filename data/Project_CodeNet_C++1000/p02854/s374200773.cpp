#include "bits/stdc++.h"

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), S(N + 1);
    S[0] = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        S[i + 1] = S[i] + A[i];
    }

    long long ans = LLONG_MAX;
    for (int i = 1; i < N; ++i) {
        long long left = S[i];
        long long right = S[N] - S[i];
        ans = min(ans, abs(left - right));
    }
    cout << ans << endl;
}