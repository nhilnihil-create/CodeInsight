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
    vector<ll> A(N);
    rep(0, i, N)
    {
        cin >> A.at(i);
    }

    ll ans = 0;
    bitset<60> bit;
    rep(0, d, 60)
    {
        ll num0 = 0, num1 = 0;
        rep(0, i, N)
        {
            bit = A.at(i);
            if (bit.test(d))
            {
                num1++;
            }
            else
            {
                num0++;
            }
        }
        ans += (((num0 * num1) % MOD) * (((ll)1 << d) % MOD)) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}