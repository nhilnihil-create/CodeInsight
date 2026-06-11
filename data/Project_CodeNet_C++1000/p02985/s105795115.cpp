#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> g[200005];
bool vis[200005];
int n,k;
int mod = 1e9 + 7;
int DFS(int node,int parent){
    if(vis[node])   return 1;
    vis[node] = 1;
    int ks = k - 2;
    int ans = 1,unvisC = 0;
    if(parent == -1){
        ks = k-1;
    }
    if(k <=0)   return 0;
    for(auto j:g[node]){
        if(j != parent){
            unvisC++;
        }
    }
    for(int p = 0; p < unvisC; p++){
        ans*=ks--;
        ans%=mod;
    }

    for(auto j:g[node]){
            if(node == parent)  continue;
        ans*=DFS(j,node);
        ans%=mod;
    }

    return ans;
}
 main()
{

    cin>>n>>k;
    for(int i =0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int res = k * DFS(1,-1);
    res%=mod;
    cout<<res<<endl;

    return 0;
}
