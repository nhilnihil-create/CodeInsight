#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ep emplace_back

using namespace std;

const int  mod = 1e9 + 7;
const int e = 2000 + 69;
const int base = 311;

ll dp[e][e];

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, int>> a;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        a.ep(x, i);
    }
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        for(int le=0; le<=i+1; le++)
        {
            int ri = i - le + 1;
            int dist = n - ri +1 ;
            if(le > 0)
            {
                dp[le][ri] = max(dp[le][ri], dp[le-1][ri] + a[i].first*abs(a[i].second - le));
                ans = max(ans, dp[le][ri]);
            }
            if(ri > 0)
            {
                dp[le][ri] = max(dp[le][ri], dp[le][ri-1] + a[i].first*abs(a[i].second - dist));
                ans = max(ans, dp[le][ri]);
            }
        }
    }
    cout << ans ;
}
