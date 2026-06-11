#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long ans = 0;
    long long ma = A[0];
    for (int i = 0; i < N; i++) {
        ma = max(ma, A[i]);
        ans += ma - A[i];
    }
    cout << ans << endl;
    return 0;
}