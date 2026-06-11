#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
const double eps=1e-5;
int a[maxn],n,k;
bool check(double mval)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=floor(a[i]/mval);
	return cnt<=k;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	double l=0,r=1e9;
	while(r-l>eps)
	{
		double mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	printf("%d\n",(int)round(l+0.5));
}