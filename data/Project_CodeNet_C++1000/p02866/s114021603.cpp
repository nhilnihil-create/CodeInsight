#include <iostream>
#include <iomanip>
#include <map>
#include <utility>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 998244353;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

ll power(ll n, ll t)
{
    ll r = 1;
    repi(i, t, 0)
    {
        r *= n;
        r %= MOD;
    }
    return r % MOD;
}
int main()
{
    int n;
    cin >> n;
    map<int, int> rt;
    repi(i, n, 0)
    {
        int d;
        cin >> d;
        if(i == 0 && d != 0){
            cout << 0 << endl;
            return 0;
        }
        rt[d]++;
    }
    if (rt[0] != 1)
    {
        cout << 0 << endl;
    }
    else
    {
        ll ans = 1;
        repi(i, rt.size(), 1)
        {
            ans *= power(rt[i - 1], rt[i]);
            ans %= MOD;
        }
        cout << ans % MOD << endl;
    }
    return 0;
}