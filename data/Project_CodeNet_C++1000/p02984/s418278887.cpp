#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    
    vector<ll> ans(n);
    ans[0] = sum;
    for (int i = 0; (2 * i + 1) < n; i++) {
        ans[0] -= 2 * a[2 * i + 1];
    }

    cout << ans[0] << endl;
    rep(i, n - 1) {
        ans[i + 1] = 2 * a[i] - ans[i];
        cout << ans[i + 1] << endl;
    }
    return 0;
}
