#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
#include <ctime>
#include <tuple>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

/*
using PAIR = pair<string, int>;
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long ll;

#define fi first
#define se second
#define rep(i, n) for (ll i = 0; i < n; i++)
#define debugA() cerr << "AAAAA" << endl
#define debug_() cerr << "-------------" << endl
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v)                   \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << endl;

using Graph = vector<vector<int>>;

int main()
{
    string s;
    cin >> s;
    int MOD = 1000000007;

    vector<vector<int>> dp(100005, vector<int>(2, 0));
    dp[0][0] = 1;
    for (int i = 0; i < s.size(); i++)
    {
        // a+b==0
        if (s[i] == '0')
        {
            (dp[i + 1][0] += dp[i][0]) %= MOD;
            (dp[i + 1][1] += dp[i][1]) %= MOD;
        }
        else
        {
            (dp[i + 1][1] += (dp[i][0] + dp[i][1])) %= MOD;
        }

        // a+b==1
        if (s[i] == '0')
        {
            (dp[i + 1][1] += dp[i][1] * 2 % MOD) %= MOD;
        }
        else
        {
            (dp[i + 1][0] += dp[i][0] * 2 % MOD) %= MOD;
            (dp[i + 1][1] += dp[i][1] * 2 % MOD) %= MOD;
        }
    }
    cout << (dp[s.size()][0] + dp[s.size()][1]) % MOD << endl;
}
