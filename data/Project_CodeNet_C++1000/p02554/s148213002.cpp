#include<iostream>
#define mod 1000000007
using namespace std;

long long int power(long long int a,long long int n)
{

    long long int res = 1;

    while(n>0)
    {
        if(n&1)
            res = (res*a)%mod;

        a = (a*a)%mod;
        n = n>>1;
    }

    return (res%mod);
}
int main()
{
	long long int n,ans;
	cin>>n;

	ans = power(10,n)-power(9,n)-power(9,n)+power(8,n);
	ans%=mod;
	ans = (ans+mod)%mod;

	cout<<ans<<endl;

	return 0;
}