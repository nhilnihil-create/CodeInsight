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

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<vector<char>> grid(H + 2, vector<char>(W + 2, '#'));
    rep(1, i, H + 1)
    {
        rep(1, j, W + 1)
        {
            cin >> grid.at(i).at(j);
        }
    }

    vector<vector<ll>> d1(H + 2, vector<ll>(W + 2)), d2(H + 2, vector<ll>(W + 2));
    rep(0, i, H + 2)
    {

        ll r = 0, l, count = 0;
        rep(0, j, W + 2)
        {
            if (grid.at(i).at(j) == '#')
            {
                l = max((ll)0, j - 1);
                rep(r, k, l + 1)
                {
                    d1.at(i).at(k) = count;
                }
                d1.at(i).at(j) = 0;
                r = j + 1;
                count = 0;
                continue;
            }
            count++;
        }
    }

    rep(0, i, W + 2)
    {
        ll r = 0, l, count = 0;
        rep(0, j, H + 2)
        {
            if (grid.at(j).at(i) == '#')
            {
                l = max((ll)0, j - 1);
                rep(r, k, l + 1)
                {
                    d2.at(k).at(i) = count;
                }
                d2.at(j).at(i) = 0;
                r = j + 1;
                count = 0;
                continue;
            }
            count++;
        }
    }

    ll ans = 0;
    rep(0, i, H + 2)
    {
        rep(0, j, W + 2)
        {
            ans = max(d1.at(i).at(j) + d2.at(i).at(j) - 1, ans);
        }
    }

    cout << ans << endl;
}