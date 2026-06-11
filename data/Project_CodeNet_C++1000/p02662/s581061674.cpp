#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod = 1e9 + 7;
const ll mmod = 998244353;

vector<ll> dx = {1, -1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

vector<vector<ll>> g;
vector<vector<ll>> par;
vector<vector<ll>> dp;
vector<ll> d;


int main() {
    
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(3001));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < dp[i].size(); ++j)
        {
            dp[i][j] = dp[i - 1][j] * 2ll;
            dp[i][j] %= mmod;
            if (j >= a[i - 1])
            {
                dp[i][j] += dp[i - 1][j - a[i - 1]];
                dp[i][j] %= mmod;
            }
        }
    }
    
    cout << dp[n][s] << endl;

    
    return 0;
}