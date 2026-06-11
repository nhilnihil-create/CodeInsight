#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
int main()
{
    vector<ll>v;
    for(ll i=1;i<=9;i++)
    {
        for(ll j=1;j<=9;j++)
        {
            v.pb(i*j);
        }
    }
    ll a; cin>>a;
    for(ll i=0;i<v.size();i++)
    {
        if(v[i]==a)
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}
