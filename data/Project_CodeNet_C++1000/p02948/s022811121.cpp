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

#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
#define repd(i, n) for (ll i = (n)-1; i >= 0; --i)
#define INF 10e12
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(n);
    rep(i, 0, n) cin >> v[i].first >> v[i].second;
    sort(all(v));
    ll ans = 0, j = 0;
    priority_queue<ll> q;
    rep(i, 1, m + 1)
    {
        while (v[j].first <= i && j < n)
        {
            q.push(v[j].second);
            j++;
        }
        if (q.empty())
            continue;
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
}