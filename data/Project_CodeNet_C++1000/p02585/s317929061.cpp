#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

#define INF ((1<<30)-1)
#define LLINF (1LL<<60)
#define EPS (1e-10)

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N), C(N);
    rep(i, N) cin >> P[i], P[i]--;
    rep(i, N) cin >> C[i];

    ll ans = -INF;

    rep(i, N) {
        int v = i;
        ll cycle_sum = 0;
        int cycle_cnt = 0;

        while (true) {
            cycle_cnt++;
            cycle_sum += C[v];
            v = P[v];
            if (v == i) break;
        }

        ll path = 0;
        int cnt = 0;

        while (true) {
            cnt++;
            path += C[v];

            if (cnt > K) break;

            int num = (K - cnt) / cycle_cnt;
            ll score = path + max(0LL, cycle_sum) * num;
            ans = max(ans, score);

            v = P[v];
            if (v == i) break;
        }
    }

    cout << ans << endl;
}
