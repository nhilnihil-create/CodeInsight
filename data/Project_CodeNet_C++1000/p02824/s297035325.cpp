#include<bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; ++ i) 
#define N 100010
using namespace std;
int n,m,v,p,a[N],ans,a1;
inline bool cmp(int i, int j)
{
	return i>j;
}
inline int read()
{
	char cc = getchar(); int cn(0), flus(1);
	while(cc > '9' || cc < '0') {if(cc == '-') flus = -flus; cc = getchar();};
	while(cc >= '0' && cc <= '9') {cn = cn * 10 + cc - '0'; cc = getchar();};
	return flus * cn;
}
signed main()
{
	n = read();
	m = read();
	v = read();
	p = read();
	//scanf("%lld%lld%lld%lld",&n,&m,&v,&p);
	ans=p;
	rep(i, 1, n) a[i] = read();
	sort(a+1, a+n+1, cmp);
	rep(i, p + 1, n)
	{
		if(a[i] + m < a[p]) break;
		if(v <= p + n - i) ++ans;
		else if(((v - p - n + i) * m - a1 - 1) / (i - p) + 1 + a[p] <= a[i] + m) ++ans;
		a1 += a[p] - a[i];
	}
	printf("%lld",ans);
	return 0;
 }
