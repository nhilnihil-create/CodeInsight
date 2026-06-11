#include<bits/stdc++.h>
#define ll long long
#define f first
#define  s second
#define pii pair<int,int>
#define pll pair<ll,l>
#define ull unsigned ll
#define mp make_pair
#define pb push_back

using namespace std;

ll n;
ll a[200001];
ll k;

bool check(ll len){
    ll cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=a[i]/len-1;
		if(a[i]%len>0)cnt++;
	}
	if(cnt<=k){
		return true;
	}
	return false;
}



int main(){
	cin>>n>>k;
	for(ll i=1;i<=n;i++)cin>>a[i];
	ll mx=-1;
	for(ll i=1;i<=n;i++)mx=max(mx,a[i]);
	ll ans=mx;
	ll l,r;
	l=1,r=mx;
	while(l<r){
		ll m=(l+r)/2;
		if(check(m))ans=m,r=m;
		else l=m+1;
	}
	cout<<ans;
	return 0;
}