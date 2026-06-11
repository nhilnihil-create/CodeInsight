#include<bits/stdc++.h>
 
using namespace std;

const long long mod=1e9+7;
 
long long zzs(long long a,long long b) 
{
    long long sq=1;
    while(b)
	{
        if(b&1) 
            sq=sq*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return sq;
}
int main() 
{
    long long n;
    cin>>n; 
    cout<<((zzs(10ll,n)-2*zzs(9ll,n)+zzs(8ll,n))%mod+mod)%mod<<endl;
    return 0;
}