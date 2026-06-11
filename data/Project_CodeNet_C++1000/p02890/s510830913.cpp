#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#define ll long long
#define inf 0x3f3f3f3f
#define maxn 500010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
inline void write(ll x)
{
	static char buf[20];
	int len=0;
	if(x<0)putchar('-'),x=-x;
	for(;x;x/=10)buf[len++]=x%10+'0';
	if(!len)putchar('0');
	else while(len)putchar(buf[--len]);
}
inline void writesp(ll x){write(x); putchar(' ');}
inline void writeln(ll x){write(x); putchar('\n');}
int cnt[maxn];
ll a[maxn],sum[maxn];
int n,tot;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read(),++cnt[a[i]];
	tot=0;
	for(int i=1;i<=n;i++)
		if(cnt[i])a[++tot]=cnt[i];
	std::sort(a+1,a+tot+1,std::greater<int>());
	sum[tot+1]=0;
	for(int i=tot;i;i--)
		sum[i]=sum[i+1]+a[i];
	for(int i=1;i<=n;i++){
		if(i==1){
			writeln(n); continue;
		}
		if(i>tot){
			puts("0"); continue;
		}
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(sum[mid+1]/(i-mid)>=a[mid])r=mid;
			else l=mid+1;
		}
		writeln(sum[l]/(i-l+1));
	}
}