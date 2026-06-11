#include <bits/stdc++.h>
#define sort stable_sort 
using namespace std;

int _;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int mod=1e9+7;

int n;

inline long long powlog(int x,int t)
{
	long long ans=1;
	while(t--)
	{
		ans *= x;
		ans %= mod;
	} 
	return ans;
}

int main()
{	
	//for(scanf("%d",&_);_;_--)
	scanf("%d",&n);
	printf("%lld\n",(powlog(10,n)-powlog(9,n)-powlog(9,n)+powlog(8,n)+2*mod)%mod);
	return 0;
}   	         
