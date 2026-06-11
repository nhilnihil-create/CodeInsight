#include<bits/stdc++.h>
#define ll long long
#define vl vector
#define pb push_back
#define ff first
#define ss second
using namespace std;

vl<ll> divisor(ll n)
{
    vl<ll> v;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0) 
        {
            if(n/i==i) v.pb(i);
            else
            {
                v.pb(i);
                v.pb(n/i);
            }
        }
    }
    return v;
}

int main()
{
    ll a,b,i,j,n,m,k,t;
    cin>>n>>m;
    priority_queue<ll> q;
    for(i=0;i<n;i++)
    {
        cin>>a;
        q.push(a);
    }
    for(i=0;i<m;i++)
    {
        a=q.top();
        q.pop();
        a/=2;
        q.push(a);
    }
    ll ans=0;
    while(!q.empty())
    {
        a=q.top();
        ans+=a;
        q.pop();
    }
    cout<<ans;
}