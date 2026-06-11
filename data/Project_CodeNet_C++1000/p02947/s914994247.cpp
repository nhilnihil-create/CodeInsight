#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

using ll = long long;

#define fi first
#define se second

int nPr(int in, int ir)
{
    if(in<ir)return 0;
    int ret=1;
    for(int i=in;i>=ir+1;i--)ret*=i;
    return ret;
}

ll nCr(ll in, ll ir)
{
    if(in<ir)return 0;
    ll a=1,b=1;
    for(;ir>=1;ir--,in--){a*=in;b*=ir;}
    ll ret=a/b;
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    vector<int[26]> s(n);

    map<str,int> m;

    for(int i=0;i<n;i++)
    {
        str is;cin>>is;
        for(int j=0;j<is.size();j++)s[i][is[j]-'a']++;

        ss makefi;
        for(int j=0;j<26;j++)makefi<<char(s[i][j]+'0');
        m[makefi.str()]++;
    }

    ll ans=0;

    for(auto mm:m)
    {
        if(mm.se>=2)
        {
            ans+=nCr(mm.se,2);
        }
    }

    cout<<ans<<"\n";

    return 0;
}
