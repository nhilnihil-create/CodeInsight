#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for(auto &e : A) cin >> e;
    int64_t S = accumulate(A.begin(), A.end(), 0LL);
    int64_t T = 0;
    for(int i = 1; i < N; i += 2) T += A[i];
    vector<int> B(N);
    B[0] = S - 2LL * T;
    rep(i, N - 1) B[i + 1] = 2 * (A[i] - B[i] / 2);
    rep(i, N) cout << B[i] << " ";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
