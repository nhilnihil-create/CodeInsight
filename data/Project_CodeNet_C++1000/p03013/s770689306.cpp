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

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

const long long MOD = 1e9 + 7;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<ll> stair(N + 1, 0);
    rep(i, M)
    {
        ll tmp;
        cin >> tmp;
        stair[tmp] = 1;
    }
    vector<ll> dp(N + 1, 0);
    dp[0] = 1;
    for (ll i = 0; i < N; ++i)
    {
        if (stair[i + 1] != 1)
            if (i == 0)
                dp[i + 1] = dp[i];
            else
                dp[i + 1] = dp[i] + dp[i - 1];
        dp[i + 1] %= MOD;
    }
    cout << dp[N] << endl;
}