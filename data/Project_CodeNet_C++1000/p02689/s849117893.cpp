#include<bits/stdc++.h>
using namespace std;
//#define int long long

int main(){
    vector<int>adj[100001];
    int n,m;
    cin>>n>>m;
    int h[100001];
    for(int i=1;i<=n;i++)
        cin>>h[i];
//    cout<<n<<endl;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
//        if(find(adj[u].begin(),adj[u].end(),v)==adj[u].end())
        adj[u].push_back(h[v]);
//        if(find(adj[v].begin(),adj[v].end(),u)==adj[v].end())
        adj[v].push_back(h[u]);
    }
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()>0)
            sort(adj[i].begin(),adj[i].end());
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()==0)
            ans+=1;
        else
        {
            if(h[i]>adj[i][adj[i].size()-1])
                ans+=1;
        }
    }
    cout<<ans<<endl;
}