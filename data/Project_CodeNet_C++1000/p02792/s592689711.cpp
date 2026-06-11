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
    ll N;
    cin >> N;
    vector<vector<ll>> c(10, vector<ll>(10, 0));
    rep(1, i, N + 1)
    {
        ll tmp = i;
        ll t, d;
        d = tmp % 10;
        while (tmp > 9)
        {
            tmp /= 10;
        }
        t = tmp;
        c.at(t).at(d)++;
    }
    ll ans = 0;
    rep(1, i, 10)
    {
        rep(1, j, 10)
        {
            ans += c.at(i).at(j) * c.at(j).at(i);
        }
    }
    cout << ans << endl;
}