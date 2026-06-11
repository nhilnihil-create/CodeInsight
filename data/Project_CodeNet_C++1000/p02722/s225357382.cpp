#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;

    int ans = 0;
    for(ll i=1; i*i<=n; i++)
    {
        if((n-1)%i==0)
        {
            // cout << i << ' ' << (n-1)/i << endl;
            if(i*i != n-1) ans+=2;
            else ans++;
        }
        else if(n%i==0)
        {
            ll m = n;
            while(m%i==0 && m >= i) m/=i;
            if(m%i==1)
            {
                // cout << i << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}