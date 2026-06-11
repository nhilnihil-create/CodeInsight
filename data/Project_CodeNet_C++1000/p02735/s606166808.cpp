#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define mod 1000000007
#define string_mod 2549536629329_base_255
#define pb push_back
#define F first
#define S second
#define ff first
#define endl "\n"
#define ss second
#define all(v) v.begin(), v.end()
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res % p;
}
int n, q;
int fn[1000005];
void update(int i, int add)
{
    while (i > 0 && i < n+1)
    {
        fn[i] += add;
        i = i + (i & (-i));
    }
}
int sum(int i)
{
    int s = 0;
    while (i > 0)
    {
        s = s + fn[i];
        i = i - (i & (-i));
    }
    return s;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    tc = 1; // cin >> tc;
    while (tc--)
    {
        int r, c;
        cin >> r >> c;
        int dp[r][c];
        string s[r];
        for (int i = 0; i < r;i++){
            cin >> s[i];
        }
        dp[0][0] = 0;
        if(s[0][0]=='#'){
            dp[0][0] = 1;
        }
        for (int i = 1; i < c;i++){
            int f = 0;
            if(s[0][i]=='#'&&s[0][i-1]=='.')
                f = 1;
            dp[0][i] = dp[0][i - 1] + f;
        }
        for (int i = 1; i < r;i++){
            int f = 0;
            if (s[i][0] == '#'&&s[i-1][0]=='.')
                f = 1;
            dp[i][0] = dp[i - 1][0] + f;
        }
        for (int i = 1; i <r;i++){
            for (int j = 1; j <c;j++){
                int f = 0;
                if(s[i][j]=='.')
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + f;
                else
                    dp[i][j] = min(dp[i - 1][j] + (s[i - 1][j] == '.'), dp[i][j - 1] + (s[i][j - 1] == '.'));
            }
        }
        // for (int i = 0; i < r; i++)
        // {
        //     for (int j = 0; j < c; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << dp[r - 1][c - 1] << endl;
    }

    return 0;
}
