#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
typedef long long ll;
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

ll N, ans = 0;
string s;

void solve(ll n, ll now)
{
    if (n == 3)
    {
        ans++;
        return;
    }
    for (ll i = 0; i <= 9; i++)
    {
        for (ll j = now; j <= N - 3 + n; j++)
        {
            if (s.at(j) == (char)('0' + i))
            {
                solve(n + 1, j + 1);
                break;
            }
        }
    }
    return;
}

int main()
{
    cin >> N >> s;
    solve(0, 0);
    cout << ans << endl;
}