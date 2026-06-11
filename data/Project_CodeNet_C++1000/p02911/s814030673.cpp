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
    cin>>n>>k>>t;
    ll arr[n];
    for(i=0;i<n;i++) arr[i]=k;
    for(i=0;i<t;i++)
    {
        cin>>a;
        a--;
        arr[a]++;
    }
    for(i=0;i<n;i++) arr[i]-=t;
    for(i=0;i<n;i++)
    {
        if(arr[i]<=0) cout<<"No";
        else cout<<"Yes";
        cout<<endl;
    }
}