#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

using Graph = vector<Vi>;

bool topological_sort(std::vector<int>& res, const Graph& g) {
    const int n = static_cast<int>(g.size());
    res.resize(n);
    int idx = 0;

    int e = 0;
    std::vector<int> indeg(n);
    for (const auto& ch : g) {
        for (const auto& to : ch) {
            ++indeg[to];
            ++e;
        }
    }

    std::stack<int> st;
    for (int i = 0; i < n; ++i) {
        if (indeg[i] == 0) st.push(i);
    }

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        res[idx++] = u;
        for (const auto& to : g[u]) {
            --indeg[to];
            --e;
            if (indeg[to] == 0) st.push(to);
        }
    }

    if (e > 0) {
        res.clear();
        return false;
    }

    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<Pii> matches;
    matches.reserve(N * (N - 1) / 2);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            matches.emplace_back(i, j);
        }
    }

    Graph g(N * (N - 1) / 2);

    int prev_idx;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            int a;
            cin >> a;
            --a;

            Pii key = make_pair(min(i, a), max(i, a));

            int now_idx = lower_bound(matches.begin(), matches.end(), key) - matches.begin();
            if (j != 0) {
                g[prev_idx].push_back(now_idx);
            }

            prev_idx = now_idx;
        }
    }

    Vi topo;
    topological_sort(topo, g);

    if (topo.size() == 0) {
        cout << -1 << endl;
        return 0;
    }

    Vi match_days(N);
    for (int i = 0; i < N * (N - 1) / 2; i++) {
        int a, b;
        tie(a, b) = matches[topo[i]];
        int s = max(match_days[a], match_days[b]);
        match_days[a] = match_days[b] = s + 1;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, match_days[i]);
    }

    cout << ans << endl;

    return 0;
}