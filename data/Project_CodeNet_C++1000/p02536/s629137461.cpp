#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

void dfs(const vector<vector<int>>& graph, vector<int>& groups, int node, int group) {
    groups[node] = group;
    for (auto& nxt_node : graph[node]) {
        if (groups[nxt_node] < 0) {
            dfs(graph, groups, nxt_node, group);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int u, v;
    vector<vector<int>> graph(N);
    rep(i, 0, M) {
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> groups(N, -1);
    int group = 0;
    rep(i, 0, N) {
        if (groups[i] < 0) {
            dfs(graph, groups, i, group);
            ++group;
        }
    }
    cout << group - 1 << endl;
    return 0;
}