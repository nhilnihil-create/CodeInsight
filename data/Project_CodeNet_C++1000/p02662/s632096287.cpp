#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 998244353
#define int long long int
#define double long double
#define inf (int)(1e15)
#define all(x) (x).begin(), (x).end()
#define pair pair<int, int>
typedef vector<int> vi;   // Vector of long long
typedef vector<vi> vvi;   // Vector of vi
typedef vector<pair> vii; // Vector of pairs
typedef vector<vii> vvii; // Vector of Vector of pairs
typedef vector<bool> vb;  // Vector of bool
#define pq priority_queue // Max heap (To convert to min heap, use negative sign before every value)
#define ff first          // For pairs
#define ss second
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, -1, 0, 1};
const int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}, dy8[] = {1, -1, 1, 0, -1, 1, -0, -1};
#define testcases(t) \
    int(t);          \
    cin >> (t);      \
    while ((t)--)
int n, s, modinv;
vi a;
int power(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        b = b / 2;
        a = (a * a) % mod;
    }
    return res;
}
int modi(int a)
{
    return power(a, mod - 2);
}
signed main()
{
    cin >> n >> s;
    modinv = modi(2);
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vvi dp(n + 1, vi(s + 1, 0));
    dp[0][0] = power(2, n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i])
            {
                dp[i][j] += ((dp[i - 1][j - a[i]] * modinv) % mod);
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}
