#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("outp.txt","w",stdout);
    #endif
    ll n,i,sum=0;
    cin>>n;
    vector<ll> v(n);
    map<ll,ll> m;
    for(i=0;i<n;i++)
    {
        cin>>v[i];
        m[v[i]]++;
    }
    map<ll,ll>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        sum=sum+((it->second*(it->second-1))/2);
    }
    for(i=0;i<n;i++)
    {
        ll x=m[v[i]]-1;
        ll y=(m[v[i]]*(m[v[i]]-1))/2;
        x=(x*(x-1))/2;
        cout<<sum-y+x<<endl;
    }
}

    
