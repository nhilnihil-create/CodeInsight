#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=2e5+10;
const int mod=1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b;
    cin>>a>>b;
    if(a<=b)
        swap(a,b);
    vector<ll>num;
    int cnt=1;
    for(ll i=2;i*i<=a;i++)
    {
        if(a%i==0)
        {
            num.pb(i);
            while(a%i==0) a/=i;
        }
    }
    if(a>1)
    {
       num.pb(a);
    }
    map<ll,int>mp;
    for(ll i=2;i*i<=b;i++)
    {
        if(b%i==0)
        {
            mp[i]=1;
            while(b%i==0) b/=i;
        }
    }
    if(b>1)
        mp[b]=1;
    for(auto &v:num)
    {
        if(mp[v])
            cnt++;
    }
    cout<<cnt<<'\n';





}
