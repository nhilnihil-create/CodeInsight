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
	int n=in();int m=in();
	vector<int> a(n);
	for(auto &i:a)
	{
		i=in();
		i/=2;
	}
	
	int l=1;
	for(int i=0;i<n;i++)
	{
		l=l/__gcd(l,a[i]);
		l*=a[i];
	}
	
	for(int i=0;i<n;i++)
	{
		if((l/a[i])%2==0)
		{
			puts("0");return 0;
		}
	}
	//cout<<m/(2*l) +(m%(2*l))/l<< endl;
	cout<<(m/(2*l))+((m%(2*l))/l);
	
}