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
    cin>>a>>b;
    vl<ll> da=divisor(a),db=divisor(b);
    vl<ll> com,ans;
    for(i=0;i<da.size();i++)
    {
        for(j=0;j<db.size();j++)
        {
            if(da[i]==db[j])
            {
                com.pb(da[i]);
                break;
            }
        }
    }
    sort(com.begin(),com.end());
    ans.pb(com[0]);
    for(i=1;i<com.size();i++)
    {
        ll flag=0;
        for(j=0;j<ans.size();j++)
        {
            if(__gcd(ans[j],com[i])!=1)
            {
                flag=1;
                break;
            }
        }
        if(flag==0) ans.pb(com[i]);
    }
    //for(i=0;i<ans.size();i++) cout<<ans[i]<<" ";cout<<endl;
    cout<<ans.size();
}