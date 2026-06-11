#include<bits/stdc++.h>
using namespace std;
const int M=1000007,A=998244353,B=100000007;
int k,n;
long long a[100005],s,p[65],i,j,ans;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s^=a[i];
	}
	for(i=1;i<=n;i++)
		for(j=60;j>=0;j--)
			if(((s>>j)&1)==0)
				if((a[i]>>j)&1)
					if(p[j]==0)
					{
						p[j]=a[i];
						break;
					}
					else
						a[i]^=p[j];
	for(i=60;i>=0;i--)
		if(((ans>>i)&1)^1)
			ans^=p[i];
	cout<<ans+(s^ans);
}