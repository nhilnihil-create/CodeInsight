#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 1e18;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    int s;
    cin >> s;
    vector<ll> dp(s+1, 0);
    dp[0] = 1;
    for(int i = 3; i <= s; i++) {
        dp[i] = (dp[i-1] + dp[i-3]) % mod;
    }
    cout << dp[s] << endl;
    return 0;
}
