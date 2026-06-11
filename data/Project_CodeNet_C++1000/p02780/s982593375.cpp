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
#define digit(a) to_string(a).size()
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
    ll n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i, 0, n) cin >> p[i];
    vector<double> cusum(n + 1, 0);
    rep(i, 0, n) cusum[i + 1] = cusum[i] + (p[i] + 1) / (double)2;
    double ans = 0;
    rep(i, 0, n - k + 1) ans = max(ans, cusum[i + k] - cusum[i]);
    cout << fixed << setprecision(15);
    cout << ans << endl;
}