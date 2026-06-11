#include <bits/stdc++.h>
#define ll long long
#define arena ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}

int main()
{
    arena
    ll n,m;
    cin>>n>>m;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
    cin>>arr[i];
    
    ll x=0;
    for(ll i=0;i<n;i++)
    {
        if(i==0)
        {
            ll temp=arr[i];
            while(temp%2==0)
            {
                temp=temp/2;
                x++;
            }
            continue;
        }
        
        ll temp1=arr[i];
        ll cnt=0;
        while(temp1%2==0)
        {
            temp1=temp1/2;
            cnt++;
        }
        if(cnt!=x)
        {
            cout<<"0";
            return 0;
        }
    }
    
    for(ll i=0;i<n;i++)
    {
        arr[i]=arr[i]/2;
    }
    
    ll ans=arr[0];
    for(ll i=1;i<n;i++)
    {
        ans=lcm(ans,arr[i]);
    }
    
    ll p=m/ans;
    if(p%2==0)
    cout<<p/2;
    else
    cout<<p/2+1;
}