#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define LOCAL 1

#include<bits/stdc++.h>
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
constexpr int R=5e6+69, INF=2e9+6969;

int x;

int main()
{
	scanf("%d", &x);
	for(int i=1;i<=360;++i)
	{
		if((x*i)%360==0) 
		{
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
