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
const ll INF = 1e18;
const double PI = acos(-1);
const int mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n);
    rep(i, n + 1) cin >> a[i];
    rep(i, n) cin >> b[i];

    ll ans = 0;
    rep(i, n) {
        int c = min(a[i], b[i]);
        b[i] -= c;
        int d = min(a[i + 1], b[i]);
        a[i + 1] -= d;
        ans += c + d;
    }
    cout << ans << endl;
    return 0;
}
