#include <bits/stdc++.h>


using namespace std;

using ll = long long;


int main() {
    ll N, X, Y;
    cin >> N >> X >> Y;

    vector<vector<ll>> graph(N + 1);
    for (ll i = 1; i < N; i++) {
        graph[i].push_back(i + 1);
        graph[i + 1].push_back(i);
    }
    graph[X].push_back(Y);
    graph[Y].push_back(X);

    vector<ll> cnt(N + 1, 0);
    for (ll i = 1; i < N; i++) {
        vector<bool> discovered(N + 1, false);
        vector<ll> d(N + 1, 0);
        queue<ll> q;

        discovered[i] = true;
        d[i] = 0;
        q.push(i);
        while (!q.empty()) {
            ll now = q.front();
            q.pop();

            for (ll e : graph[now]) {
                if (discovered[e])
                    continue;
                discovered[e] = true;
                q.push(e);
                d[e] = d[now] + 1;
            }
        }

        for (ll j = i + 1; j <= N; j++) {
            cnt[d[j]]++;
        }
    }

    for (ll i = 1; i < N; i++) {
        cout << cnt[i] << endl;
    }
}
