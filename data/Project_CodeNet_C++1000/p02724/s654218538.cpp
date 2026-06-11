#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	ll X;
	cin>>X;
	ll ans=0;
	ans+=(X/500)*1000;
	X%=500;
	ans+=(X/5)*5;
	cout<<ans<<endl;
	return 0;
}
