#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<long long> p(N);
    for (int i = 0; i < N; ++i) cin >> p[i], ++p[i]; // 1 足しておく

    // 累積和
    vector<long long> s(N+1, 0);
    for (int i = 0; i < N; ++i) s[i+1] = s[i] + p[i];

    // K 差を見ていく
    long long res = 0;
    for (int i = 0; i+K <= N; ++i) res = max(res, s[i+K] - s[i]);
    cout << fixed << setprecision(10) << (double)(res)/2 << endl;
}
