#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const ll lmt=2e5+5;
vector<ll>adj[lmt];
ll n,ans[lmt],res[lmt];
bool vis[lmt];


int main(){
	ios_base::sync_with_stdio(false);

	cin>>n;
	for(ll i=1;i<n;i++){
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vis[1]=1;
	res[1]=1;
	for(ll i=2;i<=n;i++){
		ll sz=0;
		for(ll v:adj[i]){
			if(vis[v]==1){
				sz++;
			}
		}
		res[i]=res[i-1]-(sz-1);
		vis[i]=1;
	}
	for(ll i=1;i<=n;i++){
		ans[1]+=res[i];
	}
	for(ll i=2;i<=n;i++){
		vector<ll>nei;
		for(ll v:adj[i-1]){
			if(v>i-1){
				nei.push_back(v);
			}
		}
		ll pre=n,add=0;
		for(ll j=nei.size()-1;j>=0;j--){
			add+=((pre-nei[j]+1)*((j+1)-1));
			pre=nei[j]-1;
		}
		if(!nei.empty()){
			add-=((nei[0]-1)-i+1);
		}
		if(nei.empty()){
			add=0;
			add-=(n-i+1);
		}
		ans[i]=(ans[i-1]+add);
		ans[i]--;
	}
	ll sum=0;
	for(ll i=1;i<=n;i++){
		sum+=ans[i];
	}
	cout<<sum<<endl;
}