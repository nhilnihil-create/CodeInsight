#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin >> n;
    vector <string > inp(n);
    map <string ,ll > mp;
    for(ll i=0;i<n;i++)
    {
        cin >> inp[i];
        sort(inp[i].begin(),inp[i].end());
        mp[inp[i]]++;

    }
    ll ans=0;
    for( auto x:mp )
    {
        ans+=(x.second*(x.second-1))/2;

    }
    cout << ans<<"\n";
}
