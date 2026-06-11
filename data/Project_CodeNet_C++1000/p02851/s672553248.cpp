#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll>m;
ll a[222222];
ll n,k;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)a[i]=(a[i-1]+a[i]-1)%k;
	ll ans=0;
	m[0]++;
	for(int l=0,r=1;r<=n;r++){
		if(r-l==k)m[a[l++]]--;
		ans+=m[a[r]];
		m[a[r]]++;
	}cout<<ans<<endl;
}
