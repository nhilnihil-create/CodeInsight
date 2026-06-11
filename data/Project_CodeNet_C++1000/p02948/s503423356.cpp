#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> p(N);
    rep(i, N) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());

    priority_queue<int> que;
    int now = 0;

    ll ans = 0;
    for (int cnt = 1; cnt <= M; ++cnt) {
        for (int i = now; i < N; ++i) {
            if (p[i].first <= cnt)
                que.push(p[i].second);
            else {
                now = i;
                break;
            }

            if (i == N - 1)
                now = N;
        }

        if (!que.empty()) {
            ans += que.top();
            que.pop();
        }
    }

    cout << ans << endl;

    return 0;
}