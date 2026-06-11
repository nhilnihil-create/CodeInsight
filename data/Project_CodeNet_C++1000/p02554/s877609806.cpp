#include<iostream>
using namespace std;
const long long mod = 1000000007;
long long ksm(long long x,long long y)
{
	long long ans=1%mod;
	x=x%mod;
	while(y)
	{
		if(y%2==1)
		{
			ans=ans*x%mod;
		}
		y/=2;
		x=x*x%mod;
	}
	return ans;
}
int main()
{
	long long n;
	cin>>n;
	cout<<((ksm(10,n)-2*ksm(9,n)+ksm(8,n))%mod+mod)%mod;
}