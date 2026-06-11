#include <bits/stdc++.h>

using namespace std;

const int M = 1e3 + 5; // number of nodes
const int N = M * M;
int vis[N] , low[N] , dfsTime[N] , comp_id[N] , Time;
vector<int> adj[N];
stack<int> st;
vector<vector<int> > comps;

int dfs(int node) { // add par if undirected
    if(vis[node])
        return vis[node] == 1 ? low[node] : 1e9;

    dfsTime[node] = low[node] = Time++;
    vis[node] = 1;
    st.push(node);

    for (int child : adj[node]) // in case of undirected continue if par
        low[node] = min(low[node] , dfs(child));

    if(low[node] == dfsTime[node]) {
        comps.push_back(vector<int>());
        do {
            vis[st.top()] = 2;
            comp_id[st.top()] = comps.size() - 1;
            comps.back().push_back(st.top());
            st.pop();
        } while(comps.back().back() != node);
    }

    return low[node];
}

bool tarjan(int n) {
    for (int i = 1 ;i <= n ;i++) // one based
        if(!vis[i])
            dfs(i);

    for (int i = 0 ;i < comps.size() ;i++)
        if (comps[i].size() > 1)
            return 0;

    return 1;
}


int id[M][M] , in[N];
int memo[N];
int solve (int node) {
    int &ret = memo[node];
    if (~ret)
        return ret;

    ret = 0;
    for (int c : adj[node])
        ret = max(ret , solve(c));

    return ret = ret + 1;
}

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n;
    cin >> n;

    int nxt = 0;
    for (int i = 1 ;i <= n ;i++)
        for (int j = i + 1 ;j <= n ;j++)
            id[i][j] = nxt++;

    for (int i = 1 ;i <= n ;i++) {
        int prev = -1;
        for (int j = 0 ;j < n - 1 ;j++) {
            int a = i , b;
            cin >> b;
            if (a > b) swap(a , b);
            if (~prev) {
                adj[prev].push_back(id[a][b]);
                in[id[a][b]]++;
            }
            prev = id[a][b];
        }
    }

    if (!tarjan(n)) {
        cout << -1;
        return 0;
    }

    memset(memo , -1 , sizeof memo);
    int mx = 0;
    for (int i = 0 ;i < nxt ;i++)
        if (!in[i])
            mx = max(mx , solve(i));

    cout << mx;
}
