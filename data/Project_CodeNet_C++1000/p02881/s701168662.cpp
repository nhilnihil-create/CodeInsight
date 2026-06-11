#include<bits/stdc++.h>
#define ll long long
#define vl vector
#define pb push_back
#define ld long double
#define ff first
#define ss second
using namespace std;

ll fact(ll a)
{
    if(a==0) return 1;
    else return a*fact(a-1);
}

vl<ll> divisor(ll n)
{
    vl<ll> v;
    for(int i=2;i<=sqrt(n);i++)
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
    ll i,j,n,k,t,m,a,b;
    cin>>n;
    vl<ll> v;
    v=divisor(n);
    ll mn=n-1;
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++)
    {
        for(j=0;j<v.size();j++)
        {
            a=v[i];
            b=v[j];
            if((a*b)==n) mn=min(a+b-2,mn);
        }
    }
    cout<<mn;
}