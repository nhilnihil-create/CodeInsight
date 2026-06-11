#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n, m;
    cin>>n>>m;
    ll x;
    string s;
    map<ll,ll>mp1, mp2;
    ll c = 0, p = 0;
    for(ll i=0; i<m; i++)
    {
        cin>>x;
        cin>>s;
        if(mp2[x] == 0 && s == "WA") mp1[x]++;
        if(mp2[x] == 0 && s == "AC")
        {
            mp2[x] = 1;
            p += mp1[x];
            c++;
        }
    }
    cout<<c<<" "<<p<<endl;
    return 0;
}
