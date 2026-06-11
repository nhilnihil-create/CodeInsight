#include <bits/stdc++.h>
#define ll  long long int
#define mod 1000000007
using namespace std;
vector<ll> edges[100001];
ll n,k;
ll ans;
ll fun(ll n,ll r){
    ll ans1=1;
    for(ll i=n;i>n-r;i--)ans1=(ans1%mod*i%mod)%mod;
    return ans1;
}
void dfs(ll v,ll p=-1){
   
    if(p==-1)ans=ans%mod*(fun(k-1,edges[v].size())%mod)%mod;
    else if(p==1)ans=ans%mod*(fun(k-2,edges[v].size()-1)%mod)%mod;
    else
        ans=ans%mod*(fun(k-2,edges[v].size()-1)%mod)%mod;
   
    for(auto i:edges[v]){
        if(i==p)continue;
        dfs(i,v);
    }
    
}
 
int main() {

    cin>>n>>k;
    ans=k;
    for(ll i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        edges[x].push_back(y);
         edges[y].push_back(x);
    }
  
    dfs(1);
    cout<<ans<<endl;
}

