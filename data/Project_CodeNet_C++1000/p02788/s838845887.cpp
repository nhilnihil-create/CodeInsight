#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define fi first
#define se second 
#define pb push_back
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,d,a;
	cin>>n>>d>>a; 
	vector<pair<ll,ll> >v;
	for(int i=0;i<n;i++){
		ll x,h;
		cin>>x>>h;
		v.pb({x,(h+a-1)/a});
	}
	sort(v.begin(),v.end());
	queue<pair<ll,ll> > q;
	ll ans = 0;
	ll cur = 0;
	for(int i=0;i<n;i++){
		while(!q.empty()){
			if(q.front().fi>v[i].fi)break;
			cur-=q.front().se;
			q.pop();
		}
		
		ll trt = max(0ll,v[i].se-cur);
		cur+=trt;
		if(trt)q.push({v[i].fi+d+d+1,trt});
		ans += trt;
	}
	cout<<ans<<endl;
	return 0;
}
