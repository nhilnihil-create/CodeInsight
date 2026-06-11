#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int32_t main()
{
	int n=in(),ans=0;
	int i=1;
	if(n&1){cout<<0;return 0;}
	n/=2;
	while(n>0)
	{
		ans+=(n/5);
		n/=5;
	}
	cout<<ans;
	
}