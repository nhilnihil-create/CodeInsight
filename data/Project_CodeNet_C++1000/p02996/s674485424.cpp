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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> vec(n);
    rep(i, 0, n)
    {
        ll a, b;
        cin >> a >> b;
        vec[i].first = b;
        vec[i].second = a;
    }
    sort(all(vec));
    ll time = 0;
    cout << endl;
    rep(i, 0, n)
    {
        time += vec[i].second;
        if (time > vec[i].first)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}