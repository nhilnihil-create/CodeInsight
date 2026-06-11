#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

void solve()
{
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll ans=-1e18;
    ans=max(ans,a*c);
    ans=max(ans,a*d);
    ans=max(ans,b*c);
    ans=max(ans,b*d);
    cout << ans << endl;
    
}

int main()
{
    int t=1;
    //cin >> t;
    while(t--)
    solve();

    return 0;
}  