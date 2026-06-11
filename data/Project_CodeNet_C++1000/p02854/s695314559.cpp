#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> A(N);
    for (long long i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long left = 0;
    long long right = accumulate(A.begin(), A.end(), 0LL);
    long long minAbs = right;
    for (long long i = 0; i < N; i++) {
        left += A[i];
        right -= A[i];
        minAbs = min(minAbs, abs(right - left));
    }
    cout << minAbs << endl;

    return 0;
}