#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,ans=0,i;
    unordered_map<ll,ll> mp;
    cin>>n;
    ll z=n-1;
    for(i=1;i*i<=z;i++)
    {
        if(z%i==0)
        {
            ll a=z/i;
            mp[a]=1;
            mp[i]=1;
            if(a!=i)
                ans+=2;
            else
                ans+=1;
        }
    }
    ans--;
    for(i=2;i<=1000000;i++)
    {
        if(n%i!=0)
            continue;
        if(mp[i]==0)
        {
            ll j=1,f=0,s=i;
            while(j)
            {
                ll a=n/s;
                a-=1;
                if(a%i==0)
                {
                    f=1;
                    break;
                }
                s=s*i;
                if(n%s!=0)
                    break;
            }
            if(f==1)
            {
                mp[i]=1;
                ans+=1;
            }
        }
    }
    if(mp[n]==0)
        ans+=1;
    cout<<ans;
}
