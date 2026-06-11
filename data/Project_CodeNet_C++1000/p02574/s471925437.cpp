#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
vector<ll>prime,sfac;
void sieve(int n)
{
    prime.assign(n+1,1);
    sfac.assign(n+1,1);
    for(ll i=2;i<=n;i++)
    {
        if(!prime[i])
            continue;
        sfac[i]=i;
        for(ll j=i*i;j<=n;j+=i)
        {
            prime[j]=0;
            sfac[j]=i;
        }
    }
}
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sieve(1000000);
    vector<int>fc(1000001,0);
    for(int i=0;i<n;i++)
    {
        ll no=a[i];
        while(no>1)
        {
            fc[sfac[no]]++;
            ll x=sfac[no];
            while(no%x==0)
                no=no/x;
        }
    }
    int fl=0;
    for(int i=2;i<=1000000;i++)
    {
        if(fc[i]>1)
        {
            fl=1;
            break;
        }
    }
    if(!fl)
    {
        cout<<"pairwise coprime"<<endl;
        return 0;
    }
    fl=0;
     for(int i=2;i<=1000000;i++)
    {
        if(fc[i]>=n)
        {
            fl=1;
            break;
        }
    }
    if(!fl)
    {
        cout<<"setwise coprime"<<endl;
        return 0;
    }
    cout<<"not coprime"<<endl;
}