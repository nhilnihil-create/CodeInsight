#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    unordered_map<string, bool> m;
    ll ans = 0;
    for(ll i=0; i<n; i++)
    {
        string s;
        cin>>s;
        if(m.find(s) == m.end())
        {
            m[s] = true;
            ans++;
        }
    }
    cout<<ans<<'\n';
}