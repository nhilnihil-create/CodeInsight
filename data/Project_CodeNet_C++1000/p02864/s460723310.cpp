#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::fill;

using std::setprecision;
using std::fixed;

using std::min;
using std::max;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

long long dp[303][303];
int n, k;
long long h[500];

signed main()
{
    srand(time(NULL));
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> h[i + 1], h[i + 1]++;
    h[0] = 1;
    h[n + 1] = 1;
    for (int i = 0; i <= 302; i++) for (int j = 0; j <= 302; j++) dp[i][j] = 1e18;
    dp[0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int last = 0; last < i; last++)
            {
                int cnt = i - last - 1;
                //cout << i << " " << j << " " << last << endl;
                if (cnt <= j)
                {
                    dp[i][j] = min(dp[i][j], dp[last][j - cnt] + max(0LL, h[i] - h[last]));
                }
            }
        }
    }
    ll ans = 1e18;
    for (int i = 0; i <= k; i++) ans = min(ans, dp[n + 1][i]);
    cout << ans - 1;
}
