#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    ll n;
    cin >> n;
    ll b[n-1];
    for (ll i=0;i<=n-2;i++)
    {
        cin >> b[i];
    }

    ll ans=b[0];
    for (ll i=0;i<=n-3;i++)
    {
        ans=ans+min(b[i],b[i+1]);
    }
    ans=ans+b[n-2];
    cout << ans << endl;
    
    return 0;
}