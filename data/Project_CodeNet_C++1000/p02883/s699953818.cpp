#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    long long N, K;  cin >> N >> K;
    vector<long long> A(N), F(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> F[i];
    sort(A.begin(), A.end());
    sort(F.begin(), F.end(), greater<long long>());

    long long lb = -1, ub = INF;
    while (ub - lb > 1) {
        long long mid = (lb + ub) / 2;
        bool ok = true;
        long long cnt = K;
        for (int i = 0; i < N; ++i) {
            if (A[i] * F[i] <= mid) continue;
            cnt -= A[i] - mid / F[i];
            if (cnt < 0) ok = false;
        }
        if (ok) ub = mid;
        else lb= mid;
    }
    cout << ub << endl;
}
