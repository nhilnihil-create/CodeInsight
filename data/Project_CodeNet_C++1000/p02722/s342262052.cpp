#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
void f(long long i)
{
	long long m=n;
	while(m%i==0)m/=i;
	if((m-1)%i==0)ans++;
}
int main()
{
	cin>>n;
	for(long long i=2;i*i<=n;i++)
		if(n%i==0)
		{
			f(i);
			if(i*i!=n)f(n/i);
		}
	f(n);
	for(long long i=2;i*i<=n-1;i++)
		if((n-1)%i==0)
		{
			ans++;
			if(i*i!=n-1)ans++;
		}
	if(n-1>=2)ans++;//n-1自身存在 
	cout<<ans<<endl;
	return 0;
}