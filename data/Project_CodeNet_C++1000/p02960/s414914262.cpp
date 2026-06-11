#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
string s;
int dp[N][15];
ll solve(int idx, ll sum){
    if(idx >= s.size())
        return sum == 5;
    if(dp[idx][sum] != -1)
        return dp[idx][sum];
    ll ans = 0;
    if(s[idx] != '?')
        ans = (ans + (solve(idx + 1, (((sum * 10) + s[idx] - '0') % 13))) % mod) % mod;
    else {
        for(int i = 0; i < 10; i++)
            ans = (ans + (solve(idx + 1, (((sum * 10) + i) % 13))) % mod) % mod;
    }
    dp[idx][sum] = ans;
    return dp[idx][sum];
}
int main()
{
    Hello
    cin >> s;
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0);
    return 0;
}
