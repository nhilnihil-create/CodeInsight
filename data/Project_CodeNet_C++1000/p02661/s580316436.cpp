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
#include <ctime>
#define ri register
#define inf 0x7fffffff
#define E (1)
#define mk make_pair
#define int long long
using namespace std; const int N=400010, Mod=998244353;
inline int read()
{
	int s=0, w=1; ri char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar(); return s*w;
}
void print(int x) {if(x<0) x=-x, putchar('-'); if(x>9) print(x/10); putchar(x%10+'0'); }
int n,a[N],b[N];
signed main()
{
	n=read();
	for(ri int i=1;i<=n;i++) a[i]=read(), b[i]=read();
	sort(a+1,a+1+n), sort(b+1,b+1+n);
	int p,q; p=q=0;
	if(n&1ll) p=a[(n+1)/2], q=b[(n+1)/2];
	else p=a[n/2]+a[n/2+1], q=b[n/2]+b[n/2+1];
	printf("%lld\n",q-p+1);
	return 0;
}