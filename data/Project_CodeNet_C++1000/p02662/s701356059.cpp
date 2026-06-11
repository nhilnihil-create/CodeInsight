#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <array>
#include <tuple>
#include <string>
#include <algorithm>
#include <functional> // greater など
#include <cmath>      // abs など
#include <numeric>    // accumulate など
#include <stdexcept>
#include <cassert> // assert
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

// #define NDEBUG 1
// debug用出力 https://trap.jp/post/998/
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << H << " ";
    debug_out(T...);
}
#ifdef NDEBUG
#define debug(...)
#else
#define debug(...) debug_out(__VA_ARGS__)
#endif

//////////////// //////////////// //////////////// //////////////// ////////////////
//////////////// //////////////// //////////////// //////////////// ////////////////

constexpr ll MOD = 998244353;
array<array<ll, 3009>, 3009> dp;
int n,s;
array<int, 3009> a;

int main()
{
    cin >> n >> s;
    REP(i, n)
    {
        cin >> a.at(i);
    }

    dp.at(0).at(0) = 1;
    REP(j, s + 1)
    {
        dp.at(0).at(j + 1) = 0;
    }
    REP(i, n + 1)
    {
        REP(j, s + 1)
        {
            dp.at(i + 1).at(j) = (2 * dp.at(i).at(j) %MOD +
                ((j >= a.at(i)) ? dp.at(i).at(j - a.at(i)) : 0)) %MOD;
        }
    }
    cout << dp.at(n).at(s) << endl;
}
