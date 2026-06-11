#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

vector<vector<int>> edges;
vector<bool> visited;
vector<int> ans;

void dfs(int cur) {
    if (visited[cur]) {
        return;
    }
    for (auto &next : edges[cur]) {
        dfs(next);
    }
    ans.push_back(cur);
    visited[cur] = true;
}

int main(void) {
    int V, E;
    cin >> V >> E;

    edges.resize(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        edges[t].push_back(s);
    }

    visited.resize(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (auto v : ans) {
        cout << v << endl;
    }

    return 0;
}

