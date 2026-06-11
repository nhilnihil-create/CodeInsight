#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+100;
vector<int>ve[N];
int ans[N];
int vis[N];
queue<int>q;
void bfs()
{

    q.push(1);
    vis[1]=1;
    while(q.size()){
        int k=q.front();q.pop();
        for(auto v:ve[k]){
            if(!vis[v]){
                ans[v]+=ans[k];
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
int main()
{
     ios::sync_with_stdio(0);cin.tie(0);
     int n,q;
     cin>>n>>q;
     for(int i=1;i<=n-1;i++){
         int a,b;
         cin>>a>>b;
         ve[a].push_back(b);
         ve[b].push_back(a);
     }
     for(int i=1;i<=q;i++){
        int a,b;
        cin>>a>>b;
        ans[a]+=b;
     }
     bfs();
     for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
     }
     return 0;
}
