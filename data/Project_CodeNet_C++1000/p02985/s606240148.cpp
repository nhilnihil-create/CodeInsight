#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define INF 1LL<<62
#define inf 1000000007

ll n,m,ans[100010];
vector<ll>ch[100010];
void dep(ll now){
	ll out=-2;
	if(now==0){
		out=-1;
	}
	for(ll i=0;i<ch[now].size();i++){
		ll next=ch[now][i];
		if(ans[next]!=INF){
			continue;
		}
		ans[next]=m+out;
		out--;
		dep(next);
	}
}
int main() {
	cin>>n>>m;
	for(ll i=0;i<n-1;i++){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		ch[x].push_back(y);
		ch[y].push_back(x);
	}
	for(ll i=0;i<n;i++){
		ans[i]=INF;
	}
	ans[0]=m;
	dep(0);
	ll ans2=1;
	for(ll i=0;i<n;i++){
		ans2*=ans[i];
//		cout <<ans[i]<<endl;
		ans2%=inf;
	}
	cout <<ans2;
	return 0;
}