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
constexpr int R=5e5+69, INF=2e9+6969;

int qq;

int main()
{
	int n,k,mx=0,t[R];
	scanf("%d%d", &k, &n);
	//  scanf("%d%d", &k, &k);
	for(int i=0;i<n;++i) scanf("%d", &t[i]);
	mx = t[0];
	mx = max(mx,k-t[n-1]+t[0]);
	for(int i=1;i<n;++i)
	{
		mx=max(mx,t[i]-t[i-1]);
	}
	printf("%d\n", k-mx);
	return 0;
}
