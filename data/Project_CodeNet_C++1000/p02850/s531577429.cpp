#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;//10^18
const ll mod = 1000000007;
//printf("%.10f\n", n);
ll ok[123456];
signed main() {
    ll n, a, b, ans = 0; cin >> n;
    map<ll, map<ll, ll>> m;
    vector<vector<ll> > G(123456);
    vector<ll> aa(n), bb(n);
    for (int h = 1; h < n; h++) {
        cin >> a >> b; aa[h] = a; bb[h] = b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<ll> que, mae, iro;
    for (ll i = 0; i < G[1].size(); i++) {
        que.push(G[1][i]); mae.push(1); iro.push(i + 1); ans = max(ans, i + 1);
        m[1][G[1][i]] = i + 1; m[G[1][i]][1] = i + 1;
    }
    while (que.size()) {
        ll iro9 = 1;
        for (int i = 0; i < G[que.front()].size(); i++) {
            if (G[que.front()][i] != mae.front()) {
                que.push(G[que.front()][i]); mae.push(que.front());
                if (iro9 == iro.front()) { iro9++; }
                iro.push(iro9);
                m[que.front()][G[que.front()][i]] = iro9;
                m[G[que.front()][i]][que.front()] = iro9;
                ans = max(ans, iro9); iro9++;
            }
        }
        que.pop(); mae.pop(); iro.pop();
    }
    cout << ans << endl;
    for (int h = 1; h < n; h++) {
        cout << m[aa[h]][bb[h]] << endl;
    }
	return 0;
}