#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long int
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pci pair<char,int
#define mii map<int,int>
#define mll map<long long int,long long int>
#define mci map<char,int>
#define umii unordered_map<int,int>
#define umll unordered_map<long long int,long long int>
#define umci unordered_map<char,int>
#define F first
#define S second
#define pb push_back
#define endl '\n'
#define mod 1000000007
using namespace std;
#define maxval 10003000

int main(){
   IOS;
ll t;t=1;//cin>>t;
while(t--){
ll n,m;cin>>n>>m;
vector<ll> adj[n];
for(ll i=0;i<m;i++){
    ll u,v;cin>>u>>v;
    adj[u-1].pb(v-1);
    adj[v-1].pb(u-1);
}
ll visit[n]={0};
ll ans[n]={0};
visit[0]=1;
queue<ll> q;
q.push(0);
while(!q.empty()){
    ll s=q.front();
q.pop();
    for(ll i=0;i<adj[s].size();i++){
        if(!visit[adj[s][i]]) {visit[adj[s][i]]=1;q.push(adj[s][i]);if(ans[adj[s][i]]) continue;ans[adj[s][i]]=s+1;}
    }
    
    
}
ll x=0;
for(ll i=0;i<n;i++){
    if(visit[i]==0){x=1;break;}
}
if(x) cout<<"No\n";
else{
    cout<<"Yes\n";
    for(ll i=1;i<n;i++) cout<<ans[i]<<"\n";
}

} 
    
    

    
return 0;    
}