#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string s,t;
    cin>>s>>t;
    ll sl = s.length();
    ll tl = t.length();
    ll mx=0;
    for(ll i=0;i<=sl-tl;++i)
    {
        ll cnt=0;
        for(ll j=0;j<tl;++j)
        {
            if(s[i+j] == t[j])cnt++;
        }
        mx = max(mx,cnt);
    }
    cout<<tl-mx<<endl;
    return 0;
}


