#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    ll n,i,p,x;
    scanf("%lld",&n);
    ll a[n];
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    p=1;
    x=a[0];
    for(i=1;i<n;i++)
    {
        if(x>=a[i])
            p++;
        x=min(x,a[i]);
    }
    printf("%lld\n",p);

}
