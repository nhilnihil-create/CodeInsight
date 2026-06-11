#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
typedef long long ll;
#define repran(i, a,b) for (int i = a; i<b;i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using LP = pair<ll,ll>;
using P = pair<int,ll>;
int n;
ll inf = 1e18;

int main()
{
    int n ,q;
    cin >> n >> q;
    vector<vector<int>> G(n, vector<int>());
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        --a;--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> ans(n, 0);
    rep(i, q){
        int p; ll x;
        cin >> p >>x;
        --p;
        ans[p] += x;
    }
    //dfs
    deque<int> deq;
    deq.push_back(0);
    vector<int> parent(n, -1);
    while(!deq.empty()){
        int node = deq.back();deq.pop_back();
        for (int v : G[node]){
            if(v == parent[node]) continue;
            parent[v] = node;
            ans[v] += ans[node];
            deq.push_back(v);
        }

    }
    rep(i, n) cout << ans[i] << endl;

}