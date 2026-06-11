#include <bits/stdc++.h>


using namespace std;


using ll = long long;

ll N;
vector<vector<pair<ll, ll>>> graph;
vector<bool> discovered;
vector<pair<ll, ll>> edges;
vector<ll> parent_color;


void dfs(ll start) {
    stack<ll> s;
    s.push(start);
    discovered[start] = true;

    while (!s.empty()) {
        ll now = s.top();
        s.pop();

        ll chosen = 1;
        for (auto &e : graph[now]) {
            if (discovered[e.first])
                continue;
            if (parent_color[now] == chosen)
                chosen++;

            e.second = chosen;
            parent_color[e.first] = chosen++;

            discovered[e.first] = true;
            s.push(e.first);
        }
    }
}


int main() {
    cin >> N;
    graph.resize(N + 1);
    discovered.resize(N + 1, false);
    parent_color.resize(N + 1, 0);

    for (ll i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(make_pair(b, 0));
        graph[b].push_back(make_pair(a, 0));
        edges.push_back(make_pair(a, b));
    }

    for (ll i = 0; i < N; i++) {
        sort(graph[i].begin(), graph[i].end(), [](auto l, auto r) { return l.first < r.first; });
    }

    ll start;
    ll K = 0;
    for (ll i = 0; i < N; i++) {
        if (K < graph[i].size()) {
            K = graph[i].size();
            start = i;
        }
    }

    dfs(start);

    cout << K << endl;
    for (auto e : edges) {
        auto a = find_if(graph[e.first].begin(), graph[e.first].end(), 
                    [=](pair<ll, ll> x) { return e.second == x.first; });
        auto b = find_if(graph[e.second].begin(), graph[e.second].end(),
                    [=](pair<ll, ll> x) { return e.first == x.first; });
        if (a->second != 0) {
            cout << a->second << endl;
        } else {
            cout << b->second << endl;
        }
    }
}
