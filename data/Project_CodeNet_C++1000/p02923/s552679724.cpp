#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
int main(){
	ll n; cin>>n; ll a[n];
	rep(i,n) cin>>a[i];
	ll cs=0,ans=0;
	for(int i=n-2;i>=0;i--)
		if(a[i]>=a[i+1]) cs++,ans=max(ans,cs);
		else cs=0;
	
	cout<<ans;
}
