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
constexpr ll R=1e6+69, INF=2e9+6969;

ll k,licz,w;
bitset <R> v;
bool ok = 1;

int main()
{
	scanf("%lld", &k);
	licz = 1;
	w = 7%k;
	v[w] = 1;
	if(w == 0)
	{
		puts("1");
		return 0;
	}
	while(true)
	{
		w = (10*w+7)%k;
		++licz;
		if(w == 0) break;
		if(v[w] == 1)
		{
			ok = 0;
			break;
		}
		v[w] = 1;
	}
	printf("%lld\n", (ok ? licz : -1));
	return 0;
}
