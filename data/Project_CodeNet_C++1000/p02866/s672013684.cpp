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
int power(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        b = b >> 1;
        a = (a * a) % mod;
    }
    return res;
}
signed main()
{
    int n, s, ans = 1, maxLevel = -1;
    cin >> n;
    if (n == 1)
    {
        cin >> s;
        if (s == 0)
            cout << 1 << endl;
        else
        {
            cout << 0 << endl;
        }
        return 0;
    }
    vi sz(n + 1, 0);
    for (int i = 0, level; i < n; i++)
    {
        cin >> level;
        if (i == 0 && level != 0)
            ans = 0;
        sz[level]++;
        maxLevel = max(maxLevel, level);
    }
    if (sz[0] > 1)
        ans = 0;
    for (int i = 1; i <= maxLevel; i++)
    {
        ans = (ans * (power(sz[i - 1], sz[i]))) % mod;
    }
    cout << ans << endl;
    return 0;
}