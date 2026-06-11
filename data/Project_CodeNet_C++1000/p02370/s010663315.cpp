// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector< vector<int> >
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int N, M;
Graph G(100010);
vector<int> indeg(100010, 0), out;
vector<bool> seen(100010, false);


void dfs(int u){
    queue<int> que;
    que.push(u);

    while(!que.empty()){
        int v = que.front();
        que.pop();
        seen[v] = true;
        out.push_back(v);

        rep(i, G[v].size()){
            int v2 = G[v][i];
            // if(seen[v2]) continue;
            indeg[v2]--;
            if(indeg[v2] == 0) que.push(v2);
        }

    }
}

int main(){
    cin >> N >> M;

    rep(i, M){
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        indeg[t]++;
    }

    rep(u, N){
        if(!seen[u] && indeg[u] == 0) dfs(u);
    }

    rep(i, N){
        cout << out[i] << endl;
    }
}
