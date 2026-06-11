#include<bits/stdc++.h> 
using namespace std;
const int mod=1e9+7;
long long fastpow(long long a,long long b)
{
    long long res=1;
    while(b)
	{
        if(b&1)
            res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int main()
{
	int n;
	cin>>n;
	cout<<((fastpow(10,n)-2*fastpow(9,n)+fastpow(8,n))%mod+mod)%mod<<endl;
	return 0;
}