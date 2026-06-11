#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using V = vector<int>;

int main(int argc, char const *argv[])
{
    int s; cin >> s;
    long long int dp[2010];
    int sum = 0;
    dp[0] = 0; dp[1] = 0; dp[2] = 0; dp[3] = 1;
    for (int i = 4; i < s+1; i++)
    {
        dp[i] = dp[i-1] + dp[i-3];
        dp[i] %= 1000000007;
    }
    cout << dp[s] << endl;
    return 0;
}
