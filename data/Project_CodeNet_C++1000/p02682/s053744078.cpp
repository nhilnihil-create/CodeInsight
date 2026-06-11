#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
int main(){
	ll a,b,c,k,ans=0,x; cin>>a>>b>>c>>k;
	x=min(k,a);
	ans+=x;
	k-=x;
	x=min(k,b);
	k-=x;
	x=min(k,c);
	ans-=x;
	cout<<ans;
}
