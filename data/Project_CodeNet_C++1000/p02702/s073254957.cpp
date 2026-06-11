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
int f[2020];
int32_t main()
{
	string s;
	cin>>s;int n=s.length();
	int ans=0;f[0]++;
	int rem=0;int mul=1;reverse(s.begin(),s.end());
	for(int i=0;i<n;i++)
	{
		rem+=((s[i]-'0')*mul)%2019;
		mul*=10;mul%=2019;
		rem%=2019;
		ans+=f[rem];
		f[rem]++;
	}
	cout<<ans;
	
}