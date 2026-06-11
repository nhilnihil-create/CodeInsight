#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
ll n,ch[100010];
vector<pair<ll,ll>>a[100010];
void dep(ll now,ll c){
	if(a[now].size()==1&&now!=0){
		return ;
	}
	ll cnt=1;
	for(ll i=0;i<a[now].size();i++){
		ll nexch=a[now][i].second;
		if(ch[nexch]!=0){
			continue;
		}
		if(cnt==c){
			cnt++;
		}
		ch[nexch]=cnt;
		ll nex=a[now][i].first;
		dep(nex,cnt);
		cnt++;
	}
}
int main() {
	cin>>n;
	ll ans=0;
	for(ll i=0;i<n-1;i++){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		a[y].push_back(make_pair(x,i));
		a[x].push_back(make_pair(y,i));
		ans=max({ll(a[y].size()),ll(a[x].size()),ans});
	}
	cout <<ans<<endl;
	dep(0,0);
	for(ll i=0;i<n-1;i++){
		cout <<ch[i]<<endl;
	}
	// your code goes here
	return 0;
}