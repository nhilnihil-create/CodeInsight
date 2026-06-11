//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
#define oset tree<pi, null_type,greater<pi>, rb_tree_tag,tree_order_statistics_node_update>

#define N 20003
vector<int> adj[N];
int n;

vector<int> bfs(int st)
{
    vector<int> d(n+5, -1);
    queue<int> qu;
    qu.push(st);
    d[st] = 0;
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        for(auto v: adj[u]){
            if(d[v] == -1){
                qu.push(v);
                d[v] = d[u]+1;
            }
        }
    }
    return d;
}

int main()
{
    int x, y;
    cin >> n >> x >> y;
    n++;
    for(int i=1; i<n-1; i++){
        adj[i].push_back(i+1);
        adj[i+1].push_back(i);
    }
    adj[x].push_back(y);
    adj[y].push_back(x);

    int cnt[n+5] = {0};
    for(int i=1; i<n; i++){
        vector<int> dis = bfs(i);
        for(int j=i; j<=n; j++){
            cnt[dis[j]]++;
        }
    }
    for(int i=1; i<n-1; i++){
        cout << cnt[i] << "\n";
    }

    return 0;
}
