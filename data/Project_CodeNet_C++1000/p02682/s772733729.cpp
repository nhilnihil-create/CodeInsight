#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll a,b,c,k;
    cin>>a>>b>>c>>k;
    ll sum=0;
    while(k>0)
    {
        ll x=min(k,a);
        k-=x;
        sum+=(x);
        if(k==0)
            break;
        x=min(k,b);
        k-=x;
        if(k==0)
            break;
        x=min(k,c);
        k-=x;
        sum-=(x);
        if(k==0)
            break;

    }
    cout<<sum<<endl;





}
