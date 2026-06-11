#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <set>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n;
    cin >> n;
    vector<ll> x(n), l(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> l[i];

    vector<P> vec(n);
    for (int i = 0; i < n; ++i)
        vec[i].first = x[i] + l[i], vec[i].second = x[i] - l[i];
    sort(vec.begin(), vec.end()); // x_i + l_i に関してソート
    ll ans = 0;
    ll right = -1000000000;
    for (int k = 0; k < n; ++k)
    {
        if (right <= vec[k].second)
        {
            ++ans;
            right = vec[k].first;
        }
    }
    cout << ans << endl;
    return 0;
}
