#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    string s;
    cin>>s;
    vector<int> dp(2019, 0);
    dp[s[0] - '0'] += 1;
    ll ans = 0;
    for(ll i=1; i<s.size(); i++)
    {
        ll d  = s[i] - '0';
        vector<int> t(2019, 0);
        t[d] += 1;
        for(ll j=0; j<2019; j++)
        {
            ll r = (10*j + d)%2019;
            t[r] += dp[j];
            if(r == 0)
            {
                ans = ans + dp[j];
            }
        }
        for(int j=0; j<2019; j++)
        {
            dp[j] = t[j];
        }
    }
    cout<<ans<<'\n';
}