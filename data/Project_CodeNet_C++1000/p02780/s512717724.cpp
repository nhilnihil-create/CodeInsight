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
int t[R];
double E[R];

int main()
{
	int n,k;
	scanf("%d%d", &n, &k);
	E[0]=0;
	for(int i=1;i<=n;++i)
	{
		int x;
		scanf("%d", &x);
		E[i] = (double)(x+1)/2;
		//  E[i] += E[i-1];
	}
	double sum = 0.0,ans = 0.0;
	for(int i=1;i<=k;++i) sum += E[i];
	ans = sum;
	for(int i=k+1;i<=n;++i)
	{
		sum -= E[i-k];
		sum += E[i];
		ans = max(ans,sum);
	}
	printf("%.2lf\n", ans);
	return 0;
}
