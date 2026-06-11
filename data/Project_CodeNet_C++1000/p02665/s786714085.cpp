#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void) {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N+1), B(N+1);
    for(int64_t i=0; i<=N; i++) {
        cin >> A[i];
    }

    partial_sum(A.rbegin(), A.rend(), B.rbegin());

    int64_t ans = 0;
    int64_t now = 1;
    for(int64_t i=0; i<=N; i++) {
        if(A[i] > now) {
            cout << -1 << endl;
            return 0;
        } else {
            ans += now;
            now = (now - A[i]) * 2;
            now = min(now, B[i+1]);
        }
    }

    cout << ans << endl;
    return 0;
}
