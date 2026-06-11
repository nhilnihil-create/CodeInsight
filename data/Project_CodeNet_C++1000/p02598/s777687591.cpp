#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define LOCAL 1

#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define dbg(...) cout<<#__VA_ARGS__ ": ["; for(auto e: __VA_ARGS__){cout<<e<<", ";} cout<<"]\n"
#define dbg1(...) cout<<#__VA_ARGS__ " "<< __VA_ARGS__ 
#else
#define dbg(...) 1;
#define dbg1(...) 1;
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
constexpr ll R=2e5+69, INF=2e9+6969;

ll l,r,n,k,a[R],ans;

int main()
{
	scanf("%lld%lld", &n, &k);
	for(int i=0;i<n;++i) scanf("%lld", &a[i]);
	ans = INF;
	l = 1;
	r = INF;
	//  #warning change here :)
	while(l<r)
	{
		ll s = (l+r)/2;
		//  printf("%lld\n", s);
		ll licz = 0;
		for(int i=0;i<n;++i) licz += ((s-1 + a[i])/s - 1);
		if(k>=licz)
		{
			ans = s;
			r = s;
		}
		else l = s + 1;
	}
	printf("%lld\n", ans);
	return 0;
}
