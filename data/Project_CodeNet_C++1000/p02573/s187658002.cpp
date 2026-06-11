#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define PI 3.1415926535897932384626433
#define ceil1(a,b)   (a+(b-1))/b
#define all(v)  v.begin(),v.end()
#define gen(arr,n,nxt)  generate(arr,arr+n,nxt)
#define base ios_base::sync_with_stdio(false);cin.tie(0);
#define open freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
using namespace std;
const int mo=1e9+7;
int nxt(){int x;cin>>x;return x;}
int mod(int n,int m){int ans=n%m;if(ans<0)ans+=m;return ans;}
vector<int>adj[200001];
bool vis[200001];
int cnt=0;
void dfs(int u,int sum=1){
    cnt++;
    vis[u]=1;
    bool ok=0;
    for(auto v:adj[u]){
        if(!vis[v])
            dfs(v,sum+1);
    }
    return;
}
int32_t main(){
    base
    int n=nxt(),m=nxt();
    for(int i=0;i<m;i++){
        int x=nxt()-1,y=nxt()-1;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int Max=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cnt=0;
            dfs(i);
            Max=max(Max,cnt);
        }
    }
    cout<<Max;
    return 0;
}
