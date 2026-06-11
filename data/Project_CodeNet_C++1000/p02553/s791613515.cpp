#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi 3.141592653589793238
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007


void solve()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<max({a*c,a*d,b*c,b*d});
    return;
}

int main()
{
    FAST;
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
      #endif
    ll q;
    q=1;
    // sieve();
    // cin>>q;
    while(q--)
        solve();
    return 0;
}
