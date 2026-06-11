#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const long long INF = 2e18;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n), c(n);
    for (int i = 0; i < n; ++i) cin >> p[i], --p[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    long long ans = -INF;
    vector<bool> used(n, false);
    vector<vector<long long> > ss;
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        int cur = i;
        vector<long long> s;
        while (!used[cur]) {
            used[cur] = true;
            s.push_back(c[cur]);
            cur = p[cur];
        }
        ss.push_back(s);
    }
    for (auto vec:ss) {
        long long m = vec.size();
        vector<long long> sum(2 * m + 1, 0);
        for (int i = 0; i < 2 * m; ++i) sum[i + 1] = sum[i] + vec[i % m];

        vector<long long> rem(m, -INF);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                rem[j] = max(rem[j], sum[i + j] - sum[i]);
            }
        }

        for (int r = 0; r < m; ++r) {
            if (r > k) continue;
            long long q = (k - r) / m;
            if (r == 0 && q == 0) continue;

            if (sum[m] > 0) ans = max(ans, rem[r] + sum[m] * q);
            else if (r > 0) ans = max(ans, rem[r]);
        }
    }
    cout << ans << endl;
    return 0;
}
