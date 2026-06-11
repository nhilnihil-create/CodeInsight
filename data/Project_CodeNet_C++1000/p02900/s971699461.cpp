#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll

int32_t main()
{
	int a,b;cin>>a>>b;
	int g=__gcd(a,b);
	int ans=0;
	if(g%2==0){ans++;}while(g%2==0){g/=2;}
	for(int i=3;i<=sqrt(g);i+=2)
	{
		if(g%i==0){ans++;}
		while(g%i==0){g/=i;}
	}
	
	if(g>1)ans++;
	cout<<ans+1;
}