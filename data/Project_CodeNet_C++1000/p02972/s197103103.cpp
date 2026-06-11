#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int32_t main()
{
	
	int n=in();
	vector<int> a(n+1),ans(n+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=in();
	}
	
	int c=0;
	for(int i=n;i>=1;i--)
	{
		int ct=0;
		for(int j=i+i;j<=n;j+=i)
		if(ans[j])ct++;
		
		if(ct%2!=a[i]%2){ans[i]=1;c++;}
	}
	cout<<c<<"\n";
	for(int i=1;i<=n;i++)
	{
		if(ans[i]==1)cout<<i<<" ";
	}
}