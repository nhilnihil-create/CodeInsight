#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int MAX = 100000;
vector<int> G[MAX];
list<int> out;
vector<bool> visited;

void dfs(int u){
    visited[u] = true;
    for (auto v :G[u]) {
        if (!visited[v])dfs(v);
    }
    out.push_front(u);
}
int main(){
    //freopen("in", "r", stdin);
    int v,e;
    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        int s,t;
        cin >> s >> t;
        G[s].push_back(t);
    }

    visited.resize(v);
    for (int i = 0; i < v; ++i) {
        if (!visited[i])dfs(i);
    }
    for (auto item :out) cout << item << endl;
    return 0;
}