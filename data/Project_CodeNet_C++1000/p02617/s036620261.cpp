#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const int maxn = 200005;

int main()
{
	ll n;
	cin>>n;
	ll ans=n*(n+1)*(n+2)/6;
	for(int i=0,u,v;i<n-1;i++){
		cin>>u>>v;
		if(u>v)swap(u,v);
		ans-=(ll)u*(n-v+1);
	}
	cout<<ans<<endl;
	return 0;
}