#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
long long s[200005];
long long now;
long long ans[200005];
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	   scanf("%lld",&a[i]),a[i+n]=a[i],now+=a[i];
	int j=0;
	int k=0;
	while(j<n-1)
	{
		j+=2;
		++k;
		s[k]=s[k-1]+a[j];
	} 
	long long dx=s[k]*2;
	//cout<<now<<" "<<dx<<endl;
    for(int i=1;i<=n;i+=2)
    {
    	ans[i]=now-dx;
    	dx+=(a[i]-a[i+1])*2;
    	//cout<<dx<<endl;
	}
	for(int i=1;i<=n;++i)
	{
		if(!(i%2)) ans[i]=a[i-1]*2-ans[i-1];
		printf("%lld ",ans[i]);
	}
	return 0;
}