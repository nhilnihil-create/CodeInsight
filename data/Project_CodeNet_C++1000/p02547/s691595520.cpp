#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin>>n;
    vector<pair<ll,ll> >v;
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    ll cnt=0;
    for(int i=0;i<n;i++)
    {
       // cout<<v[i].first<<" "<<v[i].second<<"\n";
        if(v[i].first==v[i].second)
            cnt++;
        else
            cnt=0;
           // cout<<cnt<<"\n";
        if(cnt==3)
            break;
    }
    if(cnt==3)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}