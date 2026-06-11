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
    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[0] = 0;
    rep(i, 0, n)
    {
        int temp;
        cin >> temp;
        v[i + 1] = v[i] + temp;
    }
    ll ans = INF;
    // rep(i, 0, n + 1) cout << v[i] << " ";
    // cout << endl;
    rep(i, 0, n) ans = min(ans, abs(ll(v[n] - v[i]) - v[i]));
    cout << ans << endl;
}