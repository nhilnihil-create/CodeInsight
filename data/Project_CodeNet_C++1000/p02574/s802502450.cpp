#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define sf scanf
#define pf printf
#define pi acos(-1)
#define time_save ios_base::sync_with_stdio(false); cin.tie(NULL);
ll ar[1000006];

#define mx 1000005
ll prime[mx];

bool vis[mx];

void sieve()
{
    ll x=sqrt((ll)mx);
    for(ll i=3; i<=x; i+=2)
        {
        if(vis[i]==0)
        {
            for(ll j=i*i; j<mx; j+=2*i)
                vis[j]=1;
        }
    }
    prime[0]=2;
    ll in=1;
    for(ll i=3; i<mx; i+=2)
    {
        if(vis[i]==0)
        {
            prime[in]=i;
            in++;
        }
    }
}
int main()
{
    sieve();
    //time_save;
    ll n,gc;
    map<ll,ll>mp;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    gc=ar[0];
    for(ll i=1;i<n;i++)
    {
        gc=__gcd(gc,ar[i]);
    }
    ll flag=0;
    if(gc==1)
    {
        for(ll i=0;i<n;i++)
        {
            ll val=ar[i];
            for(ll j=0;prime[j]<=sqrt(ar[i]);j++)
            {
                if(val%prime[j]==0)
                {
                    mp[prime[j]]++;
                    if(mp[prime[j]]>1)
                    {
                        flag=1;
                        break;
                    }
                    while(val%prime[j]==0)
                        val/=prime[j];
                }
            }
            if(val!=1)
                mp[val]++;
            if(mp[val]>1)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            cout<<"setwise coprime"<<endl;
        else
            cout<<"pairwise coprime"<<endl;
    }
    else
        cout<<"not coprime"<<endl;
    return 0;
}
