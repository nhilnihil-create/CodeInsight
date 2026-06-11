#include <bits/stdc++.h>
typedef long long int ll ;
using namespace std ;
int main()
{
    ll n,a,b,i,p=0;
    cin>>n ;
    ll result = n - 1 ;
    for(i=1;i<=sqrt(n);++i)
    {
        if(!(n % i))
        {
            a=i;
            b=n/i ;
            p=1 ;
            result=min(result , ((a - 1) + (b - 1))) ;
        }
    }
    if(p) cout<<result<<"\n";
    else cout<<n - 1<<"\n";
    return 0 ;
}
