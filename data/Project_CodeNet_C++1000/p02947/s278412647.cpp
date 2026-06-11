#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin>>n;
    map<string,int>mp;
    map<string,int>:: iterator it;
    string s;
    for(ll i=1;i<=n;i++)
    {
        cin>>s;
        sort(s.begin(),s.end());
        mp[s]++;
    }
    ll ans=0,m=0;
    for(it=mp.begin();it!=mp.end();it++)
    {
        m=it->second;
        m--;
        ans+=((m*(m+1))/2);
        m=0;
    }
    cout<<ans<<endl;
    mp.clear();
    return 0;
}
