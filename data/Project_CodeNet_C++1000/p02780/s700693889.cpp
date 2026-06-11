// 6/22 解き直し
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> p(N);
    rep(i, N) cin >> p[i];

    vector<double> exp(N);
    rep(i, N) exp[i] = (double)(1 + p[i]) / 2.0;

    // rep(i, N) cout << exp[i] << endl;

    double sum = 0;
    for (int i = 0; i < K; i++) sum += exp[i];
    double ans = sum;

    // iは右端
    for (int i = K; i < N; i++) {
        sum -= exp[i-K];
        sum += exp[i];
        ans = max(ans, sum);
    }

    cout << std::fixed << std::setprecision(15);
    cout << ans << endl;
}