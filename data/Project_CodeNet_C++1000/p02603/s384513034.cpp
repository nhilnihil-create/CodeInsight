#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(auto &e : A) cin >> e;
    int64_t ans = 1000, now = 300;
    for(int i = 0; i < N; ++i) {
        if(now < A[i]) {
            int64_t k = ans / now;
            ans += k * (A[i] - now);
            now = A[i];
        }
        now = A[i];
    }
    cout << ans << '\n';
    return 0;
}
