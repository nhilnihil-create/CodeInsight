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

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 1000000000000000000;
const double PI = acos(-1);

int main()
{
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a);
    vector<int> q(b);
    vector<int> r(c);
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    vector<int> eat;
    rep(i, x) {
        eat.push_back(p[a - 1 - i]);
    }
    rep(i, y) {
        eat.push_back(q[b - 1 - i]);
    }
    rep(i, c) {
        eat.push_back(r[i]);
    }

    sort(eat.begin(), eat.end());

    ll ans = 0;
    rep(i, x+y) {
        ans += eat[eat.size() - 1 - i];
    }
    cout << ans << endl;
    return 0;
}