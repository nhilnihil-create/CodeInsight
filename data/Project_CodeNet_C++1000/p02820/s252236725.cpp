#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,k;cin>>n>>k;
    int r,s,p;cin>>r>>s>>p;
    str t;cin>>t;

    map<char,ll> m;
    m['r']=p;
    m['s']=r;
    m['p']=s;
    m['b']=0;

    ll ans=0;

    for(int i=0;i<k;i++)for(int j=i+k;j<n;j+=k)if(t[j]==t[j-k])t[j]='b';

    for(int i=0;i<n;i++)ans+=m[t[i]];

    cout<<ans<<"\n";

    return 0;
}
