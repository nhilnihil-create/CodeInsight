#include<bits/stdc++.h>
using namespace std;
long long a,b;
int f[1000005];
int k[100005];
int main()
{
	cin>>a>>b;
	int cnt=0;
	for(int i=2;i<=1000000;++i)
	{
		if(f[i]) continue;
		k[++cnt]=i;
	    for(int j=i+i;j<=1000000;j+=i)
	       f[j]=1;
	}
	long long gcd=__gcd(a,b);
	//cout<<gcd<<endl;
	long long ans=1;
	for(int i=1;i<=cnt;++i)
	{
		if(!(gcd%k[i])) ++ans;
		while(!(gcd%k[i])) gcd/=k[i];
	}
    if(gcd!=1) ++ans;
	cout<<ans<<endl;
	return 0;
}