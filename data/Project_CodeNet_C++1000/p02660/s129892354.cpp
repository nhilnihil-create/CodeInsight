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
int c(int n)
{
	int cur=0;
	for(int i=1;n-i>=0;i++){cur++;n-=i;}
	return cur;
}
int32_t main()
{
	
	int n=in();
	int an=0;int ans=0;
	while(n%2==0){n/=2;an++;}
	ans+=c(an);an=0;
	for(int i=3;i<=sqrt(n);i+=2)
	{
		while(n%i==0){an++;n/=i;}
		ans+=c(an);
		an=0;
	}
	if(n>2)
	ans++;
	cout<<ans;

}