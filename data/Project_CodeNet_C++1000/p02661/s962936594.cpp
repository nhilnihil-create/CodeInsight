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
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){a[i]=in();b[i]=in();}
	sort(all(a));sort(all(b));
	int x,y;
	if(n&1)
	{
		x=a[n/2];y=b[n/2];
	}
	else
	{
		x=a[n/2-1]+a[n/2];
		y=b[n/2-1]+b[n/2];
	}
	
	cout<<y-x+1;
	
}