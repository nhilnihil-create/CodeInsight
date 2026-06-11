#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

const long long MOD = 1e9 + 7;
const ll num[4] = {-1, 0, 1, 0};

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<ll> vec(n);
    rep(i, 0, n) cin >> vec[i];
    vector<ll> dairi(n);
    rep(i, 0, n) dairi[i] = vec[i];
    ll i = 0;
    while (dairi[0] % 2 == 0)
    {
        rep(i, 0, n)
        {
            if (dairi[i] % 2 == 1)
            {
                cout << 0 << endl;
                return 0;
            }
            dairi[i] /= 2;
        }
    }
    rep(i, 0, n)
    {
        if (dairi[i] % 2 == 0)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    ll tmp = vec[0] / 2;
    rep(i, 0, n - 1)
    {
        tmp = tmp * ((vec[i + 1] / 2) / __gcd(tmp, vec[i + 1] / 2));
        if (tmp > m)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = (m / tmp + 1) / 2;
    cout << ans << endl;
}
