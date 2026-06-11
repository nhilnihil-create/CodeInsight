#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi acos(-1)
#define eps 1e-8
pair<int,int> a[100001];
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return atan2(1.0*a.second,1.0*a.first)<
			  atan2(1.0*b.second,1.0*b.first);
}
signed main() 
{
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].first,&a[i].second);
		if(a[i].first==a[i].second&&a[i].first==0)
			n--,i--;
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++) 
		a[n+i]=a[i];
	for(int i=1;i<=n;i++)
	{
		int sumx=0,sumy=0;
		for(int j=i;j<i+n;j++)
		{
			sumx+=a[j].first;
			sumy+=a[j].second;
			ans=max(ans,sumx*sumx+sumy*sumy);
		}
	}
	printf("%.20lf",sqrt(1.0*ans));
	return 0;
}
