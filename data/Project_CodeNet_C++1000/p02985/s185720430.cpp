#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define INF 1LL<<62
#define inf 1000000007
ll n,k,ans[100010];
vector<ll>a[100010];
void dep(ll now){
	if(now!=0&&a[now].size()==1){
		return;
	}
	ll cnt=2;
	if(now==0){
		cnt=1;
	}
	for(ll i=0;i<a[now].size();i++){
		ll next=a[now][i];
		if(ans[next]!=-1){
			continue;
		}
		ans[next]=k-cnt;
		cnt++;
		dep(next);
	}
}
int main() {
	cin>>n>>k;
	for(ll i=0;i<n-1;i++){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(ll i=0;i<n;i++){
		ans[i]=-1;
	}
	ans[0]=k;
	dep(0);
	ll ans2=1;
	for(ll i=0;i<n;i++){
	//	cout <<ans[i]<<endl;
		ans2*=ans[i];
		ans2%=inf;
	}
	cout <<ans2;
	// your code goes here
	return 0;
}