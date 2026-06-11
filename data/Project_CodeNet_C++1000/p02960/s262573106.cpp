#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int e = 1e5+ 69;
const int mod = 1e9 + 7;

ll a[e], b[e], tt[e];
ll dp[e][15];

int main()
{
    string s;
    cin >> s;
    ll n = s.size();
    dp[0][0] = 1;
    for(int i=0; i<n; i++)
    {
        ll cur;
        if(s[i] == '?') cur = -1;
        else cur = s[i] - '0';
        for(int j=0; j<10; j++)
        {
            if(cur != -1 && cur != j) continue;
            for(ll md=0; md<=12; md++)
            {
                dp[i+1][(md*10 + j)%13] += dp[i][md];
            }
        }
        for(int md=0; md<=12; md++)
        {
            dp[i+1][md] %= mod;
        }
    }
    cout << dp[n][5];
}
