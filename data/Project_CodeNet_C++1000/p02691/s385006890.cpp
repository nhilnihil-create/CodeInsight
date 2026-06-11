#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N, std::vector<long long> A) {
    vector<long long> X(N), Y(N);
    rep (i, N) X[i] = i + A[i], Y[i] = i - A[i];
    map<long long, int> cnt;
    long long ans = 0;
    rep (i, N) {
        ans += cnt[Y[i]];
        cnt[X[i]]++;
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
