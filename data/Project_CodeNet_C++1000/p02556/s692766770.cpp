#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int main()
{
    ll n;
    cin >> n;
    vector<ll> x_r;
    vector<ll> y_r;

    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        x_r.push_back(x - y);
        y_r.push_back(x + y);
    }
    sort(x_r.begin(), x_r.end());
    sort(y_r.begin(), y_r.end());

    ll ans = max(x_r.back() - x_r[0], y_r.back() - y_r[0]);
    cout << ans << endl;
    return 0;
}