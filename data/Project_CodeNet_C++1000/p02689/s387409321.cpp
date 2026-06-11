#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N, long long M, std::vector<long long> H,
           std::vector<long long> A, std::vector<long long> B) {
    vector<long long> H2(N);
    rep (i, M) {
        A[i]--; B[i]--;
        H2[A[i]] = max(H2[A[i]], H[B[i]]);
        H2[B[i]] = max(H2[B[i]], H[A[i]]);
    }
    int ans = 0;
    rep (i, N) if (H[i] > H2[i]) ans++;
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long M;
    scanf("%lld", &M);
    std::vector<long long> H(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &H[i]);
    }
    std::vector<long long> A(M);
    std::vector<long long> B(M);
    for (int i = 0; i < M; i++) {
        scanf("%lld", &A[i]);
        scanf("%lld", &B[i]);
    }
    solve(N, M, std::move(H), std::move(A), std::move(B));
    return 0;
}
