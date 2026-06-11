#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
ll go(ll a[],ll b[],ll n,ll m)
{
    for(ll i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            return -1;
        }
    }
    return m;
}
int main()
{
    ft
    ll t,i,j,k,n,m=1,l=-1,r=-1;
    cin>>n;
    ll a[n+2],b[n+2],c[n+2];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(i=0;i<n;i++)
    {
        c[i]=i+1;
    }
    do
    {
        l=max(l,go(c,a,n,m));
        r=max(r,go(c,b,n,m));
        m++;
    }while(next_permutation(c,c+n));
    cout<<abs(l-r)<<"\n";
    return 0;
}