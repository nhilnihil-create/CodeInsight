#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int N=220002,M=10010,mod=998244353;
ll n,m,T,k,h,w,cnt,x,y,z,indx,t,ans,a[N],r[N],c[N],b[N];
string s;
int main()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	if (n==1)
	{
		printf("0");
		return 0;
	}
	ans+=a[1];
	int m=n-2;
	for (int i=2;i<=n;i++)
	{
		if (m>1) m-=2,ans+=a[i]*2;
			else if (m) m--,ans+=a[i];
	}
	printf("%lld",ans);
}