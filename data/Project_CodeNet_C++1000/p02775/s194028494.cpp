#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define LEN(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vpii = vector<pii>;

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

const int N = 1e6 + 10;
int dp[N][2];
int n;
string s;

int solve(int i, bool j)
{
    if(i == n) return j;

    int& ans = dp[i][j];

    if(ans == -1)
    {
        ans = INF<int>;
        int a = s[i] - '0';
        int b = 10 - (s[i] - '0');

        if(j)
        {
            ans = min(ans, solve(i + 1, j) + b - 1);
            ans = min(ans, solve(i + 1, !j) + a + 1);
        }
        else
        {
            ans = min(ans, solve(i + 1, j) + a);
            ans = min(ans, solve(i + 1, !j) + b);
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    
    cin >> s;
    n = LEN(s);
    reverse(ALL(s));

    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << endl;

    return 0;
}