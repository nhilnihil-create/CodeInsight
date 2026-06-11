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
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

ll modpow(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }

    if (b % 2 == 0)
    {
        return (modpow(a, b / 2) * modpow(a, b / 2)) % MOD;
    }
    else
    {
        return (a * modpow(a, b - 1)) % MOD;
    }
}

int main()
{
    ll N;
    cin >> N;
    ll ans = modpow(10, N) - (2 * modpow(9, N) - modpow(8, N));
    while (ans < 0)
    {
        ans += MOD;
    }
    ans %= MOD;
    cout << ans << endl;
}