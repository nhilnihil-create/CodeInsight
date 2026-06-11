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

ll pow(ll a, ll b)
{
    if (a == 0)
    {
        return 0;
    }
    if (b == 0)
    {
        return 1;
    }
    if (b % 2 == 0)
    {
        return (pow(a, b / 2) * pow(a, b / 2)) % MOD;
    }
    else
    {
        return (a * pow(a, b - 1)) % MOD;
    }
}

int main()
{
    ll N;
    cin >> N;
    map<ll, ll> mp;
    vector<ll> d(N, 0);
    rep(0, i, N)
    {
        cin >> d.at(i);
        mp[d.at(i)]++;
    }

    if (mp[0] != 1 || d.at(0) != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    sort(all(d));
    rep(1, i, N)
    {
        if ((d.at(i) - d.at(i - 1) == 0) || (d.at(i) - d.at(i - 1) == 1))
        {
            continue;
        }
        else
        {
            cout << 0 << endl;
            return 0;
        }
    }

    ll ans = 1, count = 1;
    rep(1, i, N)
    {
        ans *= pow(mp[i - 1], mp[i]);
        ans %= MOD;
        count += mp[i];
        if (count == N)
        {
            break;
        }
    }

    cout << ans << endl;
}
