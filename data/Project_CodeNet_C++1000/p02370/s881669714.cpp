#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

vector<int> topological_sort(const vector<vector<int>> &G, vector<int> in) {
    vector<int> ret;
    stack<int> st;
    for(int i = 0; i < in.size(); i++)
        if(in[i] == 0)
            st.push(i);
    while(st.size()) {
        int v = st.top();
        st.pop();
        ret.push_back(v);
        for(auto &nv : G[v]) {
            in[nv]--;
            if(in[nv] == 0)
                st.push(nv);
        }
    }
    return ret;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V, vector<int>());
    vector<int> in(V);
    rep(i, E) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        in[t]++;
    }
    auto sorted = topological_sort(G, in);
    for(auto x : sorted) {
        cout << x << endl;
    }
    return 0;
}
