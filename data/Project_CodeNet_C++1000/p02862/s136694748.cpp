#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
ll M=1e9+7;
ll BM(ll a,ll b)
{
    ll k=1;
    while(b!=0)
    {
        if(b%2==1)
        {
            k=(k*a)%M;
        }
        a=(a*a)%M;
        b/=2;
    }
    return k;
}
ll MI(ll a)
{
    return (BM(a,M-2)+M)%M;
}
int main()
{
    ft
    ll i,n,a,b,x,y,s=1;
    cin>>a>>b;
    x=(2*a-b)/3;
    y=(2*b-a)/3;
    if((a+b)%3!=0 || x<0 || y<0)
    {
        cout<<"0\n";
        return 0;
    }
    n=x+y;
    for(i=1;i<=n;i++)
    {
        s=(s*i)%M;
    }
    for(i=1;i<=x;i++)
    {
        s=(s*MI(i))%M;
    }
    for(i=1;i<=y;i++)
    {
        s=(s*MI(i))%M;
    }
    cout<<s<<"\n";
    return 0;
}