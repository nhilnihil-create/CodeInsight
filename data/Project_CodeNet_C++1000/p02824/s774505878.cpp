#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <map>
#define ri register
#define inf 0x7fffffff
#define E (1)
#define mk make_pair
#define int long long
using namespace std; const int N=200010;
inline int read()
{
	int s=0, w=1; ri char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar(); return s*w;
}
int n,m,v,p,a[N],now,res;
inline bool cp(int x,int y) { return x>y; }
signed main()
{
	n=read(), m=read(), v=read(), p=read();
	for(ri int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n,cp); now=p;
	for(ri int i=p+1;i<=n;res+=a[p]-a[i], i++)
	{
		if(a[p]>a[i]+m) break; // m 次全部加上去还不如别人不加
		if(p-1+n-i+1>=v || ((v-(p-1+n-i+1))*m-res-1)/(i-p)<=a[i]-a[p]-1+m) now++;// 否则把数都加给 i 和后面以及 p-1 和前面
		// 还有一种情况，还得给 p 到 i-1 这里放，那么尽量使得放了之后平均最小即可。 
	} printf("%lld\n",now);
	return 0;
}