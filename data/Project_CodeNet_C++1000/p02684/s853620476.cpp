#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200005][61];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	 cin>>a[i][0];
	for(int i=1;i<=60;++i)
	 for(int j=1;j<=n;++j)
	  a[j][i]=a[a[j][i-1]][i-1];
	long long i=1;
	for(long long j=60;j>=0;--j)
	 if((1ll<<j)<=k) i=a[i][j],k-=(1ll<<j);
	cout<<i;
	return 0;
}