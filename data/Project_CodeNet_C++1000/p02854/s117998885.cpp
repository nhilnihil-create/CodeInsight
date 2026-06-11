#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string.h>
#include <iostream>

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
    vector<ll> sum(N);
    ll a;
    rep(0, i, N)
    {
        cin >> a;
        if (i == 0)
        {
            sum.at(i) = a;
        }
        else
        {
            sum.at(i) = sum.at(i - 1) + a;
        }
    }

    ll ans = 10000000000000000;
    rep(0, i, N - 1)
    {
        ans = min(ans, abs(2 * sum.at(i) - sum.at(N - 1)));
    }
    cout << ans << endl;
}