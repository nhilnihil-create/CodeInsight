#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define ii pair<ll,ll>
#define mod 1000000007
#define endl '\n'
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

ll power(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2!=0){
			ans=(ans*a)%mod;
		}
		a=((a%mod)*(a%mod))%mod;
		b>>=1;
	}
	return ans;
}

void sieve(ll n){
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	for(ll p=2;p*p<=n;p++){
		if(prime[p]){
			for(ll i=p*p;i<=n;i+=p)
				prime[i]=false;
		}
	}
	for(ll p=2;p<=n;p++){
		if(prime[p])
			cout<<p<<" ";
	}
}

void dfs(ll i,bool vis[],vector<ll> adj[],ll a[],ll last){
	vis[i]=true;
	a[i]+=last;
	last=a[i];
	for(auto j:adj[i]){
		if(vis[j])
			continue;
		dfs(j,vis,adj,a,last);
	}
}

int main() {
	IOS;
	ll t=1;
	//cin>>t;
	while(t--){
		ll n,q;
		cin>>n>>q;
		vector<ll> adj[n+1];
		for(ll i=0;i<n-1;i++){
			ll p,qa;
			cin>>p>>qa;
			adj[p].push_back(qa);
			adj[qa].push_back(p);
		}
		ll a[n+1];
		memset(a,0,sizeof(a));
		for(ll i=0;i<q;i++){
			ll p,x;
			cin>>p>>x;
			a[p]+=x;
		}
		bool vis[n+1];
		memset(vis,false,sizeof(vis));
		ll val=0;
		dfs(val+1,vis,adj,a,val);
		for(ll i=1;i<=n;i++)
			cout<<a[i]<<" ";
	}
	return 0;
}