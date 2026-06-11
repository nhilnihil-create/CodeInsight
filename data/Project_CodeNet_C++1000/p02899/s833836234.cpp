#include<bits/stdc++.h>
#define ll long long
#define vl vector
#define pb push_back
#define ff first
#define ss second
using namespace std;

int main()
{
    ll a,b,i,j,n,m,k,t;
    cin>>n;
    vl<pair<ll,ll>> v;
    for(i=0;i<n;i++)
    {
        cin>>a;
        v.pb({a,i+1});
    }
    sort(v.begin(),v.end());
    for(i=0;i<n;i++) cout<<v[i].ss<<" ";
}