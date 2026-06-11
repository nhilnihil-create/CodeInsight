#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll par[214514];
ll ran[214514];
ll root(ll x){
	return par[x]==x?x:par[x]=root(par[x]);
}
void unite(ll x,ll y){
	x=root(x);
	y=root(y);
	if(x==y)return;
	if(ran[x]<ran[y])par[x]=y;
	else{
		par[y]=x;
		if(ran[x]==ran[y])ran[x]++;
	}
}
int main(){
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)par[i]=i;

	while(m--){
		ll a,b;
		cin>>a>>b;
		unite(a,b);
	}
	map<ll,ll>mp;
	for(int i=1;i<=n;i++)mp[root(i)]++;
	cout<<mp.size()-1<<endl;
	return 0;
}
