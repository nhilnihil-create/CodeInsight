#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

long long mod = 1000000007;
typedef long long ll;
typedef pair<ll, ll> P;
#define REP(i, n) for (long long i = 0; i < (n); i++)
vector<long long> dijkstra(vector<vector<pair<long long, long long>>> graph, long long s) {
    vector<long long> ans(graph.size(), -1);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>
        pq;
    pq.push({0, s});
    while (pq.size() > 0) {
        ll cur1 = 0;
        ll cur2 = 0;
        if (ans[pq.top().second] != -1) {
            pq.pop();
        } else {
            cur1 = pq.top().first;
            cur2 = pq.top().second;
            pq.pop();
            ans[cur2] = cur1;
            for (long long i = 0; i < graph[cur2].size(); i++) {
                pq.push({cur1 + graph[cur2][i].second, graph[cur2][i].first});
            }
        }
    }
    return ans;
}
signed main() {
    long long n;
    cin >> n;
    vector<ll> as(n);
    REP(i, n) { cin >> as[i]; }
    sort(as.begin(), as.end());
    vector<ll> cnt(2000777);
    ll ans = 0;
    REP(i, n) {
        if (cnt[as[i]] == 0) {
            ans++;
        } else {
            continue;
        }
        if (i != n - 1 && as[i + 1] == as[i]) {
            if (cnt[as[i]] == 0) {
                ans--;
            }
        }
        REP(j, 1000000 / as[i] + 1) { cnt[j * as[i]]++; }
    }
    cout << ans << endl;
}