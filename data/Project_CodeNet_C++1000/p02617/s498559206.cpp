#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);

const int N = 2e5+5, M = 1e6+6, OO = 0x3f3f3f3f;
int tc;

int main()
{
    FIO
    ll n; cin>>n;
    ll ans = 0;
    for(ll i = 1 ; i<= n ; i++)
        ans += (i * (n-i+1));
    for(int i = 0 ; i< n -1 ; i++)
    {
        ll u, v; 
        cin>>u>>v;
        ans -= (min(u, v) * (n - max(u, v) + (ll) 1));
    }
    cout<<ans<<endl;
    return 0;
}