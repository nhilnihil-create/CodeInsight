#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N, long long K, std::vector<long long> p) {
    vector<double> E(N);
    rep (i, N) E[i] = (p[i] + 1.0) / 2.0;
    double tmp = 0;
    rep (i, K) tmp += E[i];
    double ans = tmp;
    loop (i, K, N) {
        tmp = tmp - E[i-K] + E[i];
        ans = max(ans, tmp);
    }
    printf("%.20lf\n", ans);
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long K;
    scanf("%lld", &K);
    std::vector<long long> p(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &p[i]);
    }
    solve(N, K, std::move(p));
    return 0;
}
