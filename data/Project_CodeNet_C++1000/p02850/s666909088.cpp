#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int mod = (int)1e9+7;

void __print() {cerr << "]\n";}

template<typename T, typename... V>
void __print(T t, V... v)
{ cerr << t; if(sizeof...(v)) printf(" "); __print(v...);}

#define dbg(x...) cerr << "[" << #x << "] = ["; __print(x);



int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<pair<int, int>>> adj(n+1);
    set<int> s[n+1];
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
    }
    vector<int> colors(n);
    vector<bool> visited(n+1, false);
    queue<int> q;
    q.push(1);
    int mx = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        vector<int> v;
        int sz = adj[u].size();
        mx = max(mx, sz);
        for(int i = 1; i <= sz; i++) {
            if(s[u].find(i) == s[u].end()) {
                v.push_back(i);
            }
        }
        for(auto edge : adj[u]) {
            int to, id;
            tie(to, id) = edge;
            if(!visited[to]) {
                colors[id] = v.back();
                v.pop_back();
                q.push(to);
                s[to].insert(colors[id]);
            }
        }
    }
    printf("%d\n", mx);
    for(int i = 0; i < n-1; i++) printf("%d\n", colors[i]);
}
