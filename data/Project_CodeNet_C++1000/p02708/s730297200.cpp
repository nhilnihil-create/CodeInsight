#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
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
signed main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = k; i <= (n + 1); i++)
    {
        ans += (i * (n - i + 1));
        ans++;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}