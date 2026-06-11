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
int c[10][10], n, ans = 0, head, tail, num;
signed main()
{
    cin >> n;
    memset(c, 0, sizeof(c));
    for (int k = 1; k <= n; k++)
    {
        num = k;
        tail = num % 10;
        while (num > 0)
        {
            if (num <= 9)
                head = num;
            num /= 10;
        }
        c[head][tail]++;
    }
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            ans += (c[i][j] * c[j][i]);
        }
    }
    cout << ans << endl;
    return 0;
}