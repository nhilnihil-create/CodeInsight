#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<long long> A(N);
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    long long ans = __LONG_LONG_MAX__;
    long long left_sum = 0;
    for (int i = 0; i < N - 1; i++) {
        left_sum += A[i];
        long long l = left_sum;
        long long r = sum - l;
        ans = min(abs(l - r), ans);
    }
    cout << ans << endl;
    return 0;
}