#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int N=102,M=10010,mod=998244353;
int n,m,T,k,h,w,cnt,x,y,z,indx,t,ans,a[N][N],r[N],c[N],b[N][N];
string s;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		for (int j=0;j<m;j++)
			if (s[j]=='#') a[i][j+1]=1;
	}
	for (int i=0;i<(1<<n);i++)
		for (int j=0;j<(1<<m);j++)
		{
			int cnt1=0,cnt2=0;
			x=i; y=j;
			for (int ii=1;ii<=6;ii++) r[ii]=c[ii]=0;
			for (;x;x/=2) r[++cnt1]=x%2;
			for (;y;y/=2) c[++cnt2]=y%2;
			int sum=0;
			
			for (int ii=1;ii<=n;ii++)
				for (int jj=1;jj<=m;jj++) b[ii][jj]=a[ii][jj];
				
			for (int ii=1;ii<=n;ii++) 
				for (int jj=1;jj<=m;jj++) if (r[ii]||c[jj]) b[ii][jj]=0;
				
			for (int ii=1;ii<=n;ii++)
			{
				for (int jj=1;jj<=m;jj++)
				{
					if (b[ii][jj]) sum++;
				}
			}
			if (sum==k) ans++;
		}
	printf("%d\n",ans);
}