#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define pb push_back
#define mk make_pair
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main()
{
    fastIO;
    ll n;
    cin>>n;
    string str;
    ll x,y,val,val1;
    vector<string>v;
    map<string,ll>m;
    for(int i=0;i<n;i++)
    {
        cin>>str>>x;
        v.pb(str);
        m.insert(mk(str,x));
    }
    string str1;
    cin>>str1;
    ll pos;
    pos=find(v.begin(),v.end(),str1)-v.begin();
    ll ans=0;
    for(int i=pos+1;i<n;i++)
    {
        auto itr=m.find(v[i]);
        ans+=itr->second;
    }
    cout<<ans<<'\n';
    return 0;
}