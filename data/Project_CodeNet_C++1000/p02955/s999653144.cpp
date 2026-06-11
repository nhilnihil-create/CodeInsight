#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    vector<int> divisors;
    for (int i = 1; i * i <= sum; i++) {
        if (sum % i == 0) {
            divisors.push_back(i);
            if (i != sum / i) divisors.push_back(sum / i);
        }
    }

    int res = 0;
    vector<int> r(N);
    for (int d : divisors) {
        for (int i = 0; i < N; i++) {
            r[i] = A[i] % d;
        }
        sort(r.begin(), r.end());

        vector<int> L(N + 1), R(N + 1);
        L[0] = 0; R[N] = 0;
        for (int i = 0; i < N; i++) {
            L[i + 1] = r[i] + L[i];
        }
        for (int i = N - 1; i >= 0; i--) {
            R[i] = (d - r[i]) + R[i + 1];
        }
        for (int i = 0; i <= N; i++) {
            if (L[i] == R[i] && L[i] <= K) {
                res = max(res, d);
                break;
            }
        }
    }

    cout << res << endl;
    return 0;
}