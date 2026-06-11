#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn =2e5+10;
const int mod=1e9+7;

int mp[3005];



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int n=s.size();
    ll ans=0;
    ll now=0;
    mp[0]=1;
    ll c=1;
    for(int i=0;i<n;i++)
    {
        int x=s[i]-'0';
        if(i!=0)
            c*=10;
        c%=2019;
        x*=c;
        x%=mod;
        now+=x;
        now%=2019;
        ans+=mp[now];
        mp[now]++;

    }
    cout<<ans<<'\n';





}
