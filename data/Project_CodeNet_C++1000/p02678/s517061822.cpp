#include <bits/stdc++.h>
using namespace std;

#define ipr pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define fr(i, j, k) for (int i = j; i < k; i++)
#define rf(i, j, k) for (int i = j; i >= k; i--)
#define ll unsigned long long
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mp make_pair
#define cnt_ones(x) __builtin_popcountll(x)

#define IOS                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const int Maxn = (int)1e6;
const ld pi = acos(-1);
const int mod = (int)1e9 + 7;
const int inf = (int)1e18;

template <class T>
ostream &operator<<(ostream &out, vector<T> &A) {
    fr(i, 1, (int)A.size()) out << A[i]+1 << " ";
    return out;
}

// GRAPH ALGORITHMS

int n, e;
//int cycle_start, cycle_end;
vector<vector<int> > g;
vector<bool> vis;
vector<int> dis;
vector<int> par;

//--> Take input of given graph
void graph_inp() {
    cin >> n;
    cin >> e;
    // e = n - 1;  for a tree
    g.resize(n);
    vis.resize(n, false);
    par.resize(n, -1);
    dis.resize(n, inf);

    fr(i, 0, e) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

//void graph_print() { fr(i, 0, n) cout << g[i] << '\n'; }

void bfs(int root) {
    queue<int> q;
    q.push(root);
    dis[root] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto child : g[node])
            if (dis[child] == inf) {
                dis[child] = dis[node] + 1;
                par[child] = node;
                q.push(child);
            }
    }
    bool flag = true;
    for(auto x : dis){
        if(x == inf){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "Yes" << '\n' << par << endl;
    }else{
        cout << "No" << endl;
    }
}

int32_t main() {
    IOS graph_inp();
    bfs(0);
    return 0;
}