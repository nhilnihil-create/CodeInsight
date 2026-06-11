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

vector<ll> memo(2010, -1);

ll solve(ll now)
{
    if (memo.at(now) != -1)
    {
        return memo.at(now);
    }
    if (now == 0)
    {
        return memo.at(now) = 1;
    }
    else if (now < 3)
    {
        return memo.at(now) = 0;
    }

    ll ans = 0;

    rep(3, i, now + 1)
    {
        ans += solve(now - i);
        ans %= MOD;
    }

    return memo.at(now) = ans;
}

int main()
{
    ll S;
    cin >> S;
    cout << solve(S) << endl;
}