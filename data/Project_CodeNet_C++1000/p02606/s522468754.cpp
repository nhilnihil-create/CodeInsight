#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define all(x) x.begin(),x.end()
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define sll set<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define endl "\n"
const ll maxn = 2e5+2;

int main()
{
    fastio;
    ll i, j, k, n, l, r, d;
    vll a;

    cin>>l>>r>>d;
    ll ans=0;
    for ( i = l; i <= r; i++)
    {
        if(i%d==0)
        ans++;
    }
    
    cout<<ans<<endl;

        
    return 0;
}