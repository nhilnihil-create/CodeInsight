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
    int n, m;
    cin >> n >> m;
    priority_queue<ll> que;
    ll ans = 0;
    rep(i, 0, n)
    {
        ll tmp;
        cin >> tmp;
        que.push(tmp);
    }
    rep(i, 0, m)
    {
        ll tmp = que.top();
        que.pop();
        que.push(tmp / 2);
    }
    rep(i, 0, n)
    {
        ll tmp = que.top();
        que.pop();
        ans += tmp;
    }
    cout << ans << endl;
}