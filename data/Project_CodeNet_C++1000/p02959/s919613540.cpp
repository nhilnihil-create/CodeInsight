#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<long long int> A(N + 1, 0);
    vector<long long int> B(N, 0);
    for (int i = 0; i < N + 1; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    long long int cnt = 0;
    for (int i = 0; i < N; ++i) {
        cnt += min(A[i], B[i]);
        B[i] -= min(A[i], B[i]);
        A[i] -= min(A[i], B[i]);
        cnt += min(A[i + 1], B[i]);
        A[i + 1] -= min(A[i + 1], B[i]);
    }
    printf("%lld\n", cnt);
}
