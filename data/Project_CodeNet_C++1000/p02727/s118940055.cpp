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

int x,y,a,b,c;
int p[R],q[R],r[R];

int main()
{
	scanf("%d%d%d%d%d", &x, &y, &a, &b, &c);
	p[0]=q[0]=INF;
	for(int i=1;i<=a;++i) scanf("%d", &p[i]);
	for(int i=1;i<=b;++i) scanf("%d", &q[i]);
	for(int i=0;i<c;++i) scanf("%d", &r[i]);
	sort(p,p+a+1);
	sort(q,q+b+1);
	sort(r,r+c);
	reverse(p,p+a+1);
	reverse(r,r+c);
	reverse(q,q+b+1);
	int A,B,licz=0;
	A=x;
	B=y;
	while(r[licz]>p[A] || r[licz]>q[B])
	{
		if(p[A]<q[B])
		{
			p[A]=r[licz];
			A--;
		}
		else
		{
			q[B]=r[licz];
			B--;
		}
		++licz;
	}
	ll ans=0;
	for(int i=1;i<=x;++i) ans+=p[i];
	for(int i=1;i<=y;++i) ans+=q[i];
	printf("%lld\n", ans);
	return 0;
}
