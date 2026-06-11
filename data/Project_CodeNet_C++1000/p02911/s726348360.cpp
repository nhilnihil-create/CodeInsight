#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    ll n,x,q;
    cin>>n>>x>>q;
    map<ll,ll>m,m2;
    vector<string>v;
    for(int i=0;i<q;i++)
    {
        ll d;
        cin>>d;
        m2[d]++;
    }
    for(int i=1;i<=n;i++)
    {
        ll f=m2[i];
        ll ans=x-q+f;
        if(ans>0)
        {
            v.pb("Yes");
        }
        else
        {
            v.pb("No");
        }
        //cout<<f<<endl;
    }
    for(auto x:v)
    {
        cout<<x<<endl;
    }
}
