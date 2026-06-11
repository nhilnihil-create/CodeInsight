#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
#define N 100
#define MAX 100000
#define NIL -1
#define rep(i, n) for(int i = 0; i < (n); ++i)

int n;
vector<int> G[MAX];
int color[MAX];

void dfs_visits(int r, int id){
    stack<int> S;
    S.push(r);
    color[r] = id;
    while(!S.empty()){
        int u = S.top(); S.pop();
        rep(j, G[u].size()){
            int v = G[u][j];
            if(color[v] == NIL) {
                color[v] = id;
                S.push(v);
            }
        }
    }
}

void dfs(){
    // initialization
    rep(i, n) color[i] = NIL;
    int id = 1;
    rep(u, n){
        if (color[u] == NIL) dfs_visits(u, id++);
    }
}

int main()
{
    int s, t, m, q;
    cin >> n >> m;
    rep(i, m){
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    dfs();
    
    cin >> q;
    vector<string> ans(q);

    rep(i, q){
        cin >> s >> t;
        if(color[s] == color[t]) ans[i] = "yes";
        else ans[i] = "no";
    }

    rep(i, q){
        cout << ans[i] << endl;
    }

    return 0;
}


