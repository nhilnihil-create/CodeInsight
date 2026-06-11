#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
ll n,q;
vector<ll>ch[200010];
ll pl[200010];
ll ans[200010];
void dep(ll now,ll sum){
	for(ll i=0;i<ch[now].size();i++){
		ll nex=ch[now][i];
		if(ans[nex]!=-1){
			continue;
		}
		ans[nex]=sum+pl[nex];
		dep(nex,ans[nex]);
	}
}
int main() {
	cin>>n>>q;
	for(ll i=0;i<n-1;i++){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		ch[x].push_back(y);
		ch[y].push_back(x);
	}
	for(ll i=0;i<q;i++){
		ll now,co;
		cin>>now>>co;
		now--;
		pl[now]+=co;;
	}
	for(ll i=0;i<n;i++){
		ans[i]=-1;
	}
	ans[0]=pl[0];
	dep(0,pl[0]);
	for(ll i=0;i<n;i++){
		cout <<ans[i]<<" ";
	}
	return 0;
}