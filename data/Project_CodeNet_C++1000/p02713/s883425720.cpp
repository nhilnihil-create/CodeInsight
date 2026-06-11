#include<iostream>
using namespace std;
long long gcd(long long m,long long n)
{
    long long t;
    while(n!=0)
    {
        t=m%n;
        m=n;
        n=t;
    }
    return m;
}
int main()
{
    long long i,j,k,l,total=0,n,m=1,p;
    cin>>l;
    for(i=1;i<=l;i++)
    {
        for(j=1;j<=l;j++)
        {
            p=gcd(i,j);
            for(k=1;k<=l;k++)
            {
                total+=gcd(k,p);             
            }
        }
    }
    cout<<total<<endl;
    return 0;
}