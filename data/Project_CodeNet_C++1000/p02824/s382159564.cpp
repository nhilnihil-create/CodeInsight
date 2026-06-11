#include <bits/stdc++.h>
#define int long long
#define N 200010
using namespace std;


inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int n,m,v,p;
int a[N],tmp[N],add[N];
inline int check(int x)
{
	memset(add,0,sizeof add);
	memset(tmp,0,sizeof tmp);
	for(int i=1;i<=n;i++) if(i!=x)
		tmp[++tmp[0]]=a[i];
	int ts=a[x]+m,tp=p;
	int sum=(v-1)*m;
	for(int i=n-1;tmp[i]>ts;i--,tp--) sum-=m;
	for(int i=1;tmp[i]<ts&&i<n;i++)
	{ 
		add[i]+=min(m,ts-tmp[i]);
		sum-=add[i];
	}
	for(int i=n-1;sum>0&&tp>0&&i>=1;i--) if(tmp[i]<=ts&&add[i]<m)
	{
		sum-=m-add[i]; tp--;
	} 
	return (tp>0)&&(sum<=0);
}
signed main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&v,&p);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int l=1,r=n,ans=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout << n-ans+1 << endl;
	return 0;
}