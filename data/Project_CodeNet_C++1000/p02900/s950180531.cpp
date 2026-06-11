#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,x,n,m,s=1;
    cin>>n>>m;
    x=__gcd(n,m);
    for(i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            s++;
            while(x%i==0)
            {
                x/=i;
            }
        }
    }
    if(x!=1)
    {
        s++;
    }
    cout<<s<<"\n";
    return 0;
}