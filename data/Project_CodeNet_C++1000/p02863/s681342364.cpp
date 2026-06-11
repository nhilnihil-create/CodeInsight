#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 30005;
#define pb push_back
#define pii pair<int,int>

int t;
int n,m;
pii A[MN];
int f[MN];
int main()
{
	memset(f,0,sizeof f);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d%d",&A[i].first,&A[i].second);
//	sort(A+1,A+1+n);
	sort(A+1,A+1+n,[](pii x,pii y){if(x.first==y.first) return x.second>y.second; return x.first<y.first;});
//	for(int i=1;i<=n;++i) printf("(%d,%d,%d)\n",i,A[i].first,A[i].second);
	for(int i=1;i<=n;++i)
	{
		int a = A[i].first, b = A[i].second;
		for(int j=m-1;j>=0;--j)
		{
			f[j+a] = max(f[j+a],f[j]+b);
		}
	}
	int ans = 0;
	for(int i=0;i<6001;++i) 
	{
		ans = max(ans,f[i]);
//		printf("%d\n",f[i]);
	}
	printf("%d\n",ans);
}