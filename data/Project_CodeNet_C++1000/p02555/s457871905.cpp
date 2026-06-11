#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int main()
{
    ll s;
    cin >> s;
    vector<ll> dp(s + 5);

    for (int i = 0; i < s + 1; i++)
    {
        if (i < 3)
        {
            continue;
        }
        else if (i == 3)
        {
            dp[i] = 1;
            continue;
        }
        dp[i] = dp[i - 1] + dp[i - 3];
        dp[i] %= 1000000007;
    }
    cout << dp[s] << endl;

    return 0;
}