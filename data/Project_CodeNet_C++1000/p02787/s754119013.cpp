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
const int MOD = 998244353;

ll H, N, ans = 10000000000;
vector<ll> A(1010), B(1010);
vector<ll> memo(10010, -1);

ll solve(ll h)
{
    if (memo.at(h) != -1)
    {
        return memo.at(h);
    }
    ll res = 1000000000;
    rep(0, i, N)
    {
        if (h - A.at(i) < 0)
        {
            res = min(res, solve(0) + B.at(i));
        }
        else
        {
            res = min(res, solve(h - A.at(i)) + B.at(i));
        }
    }
    return memo.at(h) = res;
}

int main()
{
    cin >> H >> N;
    rep(0, i, N)
    {
        cin >> A.at(i) >> B.at(i);
    }
    memo.at(0) = 0;
    cout << solve(H) << endl;
}