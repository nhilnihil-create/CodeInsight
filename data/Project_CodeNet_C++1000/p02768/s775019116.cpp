#include<iostream>
#include<algorithm>
using namespace std;
const long long MAX=1000000007;
long long powmod(long long a,long long b)
{
    long long c=1;
    while(b!=0)
    {
        if(b&1)
        {
            c=a*c%MAX;
        }
        a=a*a%MAX;
        b>>=1;
    }
    return c;
}
long long nCr(long long n,long long r)
{
    long long x=1,y=1,i;
    for(i=1;i<=r;i++)
    {
        x=x*(n-(i-1))%MAX;
        y=y*i%MAX;
    }
    return x*powmod(y,MAX-2)%MAX;
}
int main()
{
    long long n,a,b,ans;
    cin>>n>>a>>b;
    ans=powmod(2,n)-1-nCr(n,a)-nCr(n,b);
    cout<<((ans%MAX)+MAX)%MAX<<endl;
    return 0;
}