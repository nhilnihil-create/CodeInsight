#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long ll;
int main(){IOS;
	int n;
	cin>>n;
	ll ans=0;
	ll mx=0;
	for(int i=0;i<n;i++){
	 ll a;
	 cin>>a;
	 mx=max(mx,a);
	 ans+=mx-a;}
	 cout<<ans<<endl;}