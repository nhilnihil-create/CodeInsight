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
    ll n,i,q,x,y;map<ll,ll> m;
    cin>>n;vector<ll> v(n+1);
    ll sum=0;
    for(i=1;i<=n;i++)
    {    
        cin>>v[i];
        m[v[i]]++;
        sum=sum+v[i];
    }
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>x>>y;
        m[y]=m[y]+m[x];
        sum=sum+((y-x)*m[x]);
        m[x]=0;
        cout<<sum<<endl;
    }
}

    
