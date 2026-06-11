#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    int N, K; cin >> N >> K;
    vector<ld> P(N);
    rep(i, N) { cin >> P[i]; }

    vector<ld> sum(N + 1);
    for (int i = 1; i <= N; i++) {
        sum[i] = (1 + P[i - 1]) * P[i - 1] / (2 * P[i - 1]);
    }
    for (int i = 1; i <= N; i++) {
        sum[i + 1] += sum[i];
    }

    ld res = -1;
    for (int i = K; i <= N; i++) {
        res = max(res, sum[i] - sum[i - K]);
    }

    cout << fixed << setprecision(10) << res << endl;
}
