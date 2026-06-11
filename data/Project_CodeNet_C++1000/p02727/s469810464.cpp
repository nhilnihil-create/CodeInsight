#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int x, y, a, b, c, u = 0, v = 0, w = 0;
    ll p[100005] = {}, q[100005] = {}, r[100005] = {}, z = 0;
    vector<pair<ll, int>> d;
    cin >> x >> y >> a >> b >> c;
    for (int i = 0; i < a; i++) cin >> p[i], d.push_back({p[i], 1});
    for (int i = 0; i < b; i++) cin >> q[i], d.push_back({q[i], 2});
    for (int i = 0; i < c; i++) cin >> r[i], d.push_back({r[i], 3});
    sort(d.begin(), d.end()); reverse(d.begin(), d.end());
    for (auto i : d) {
        if (i.second == 1) {
            if (u < x) u++, z += i.first;
        } else if (i.second == 2) {
            if (v < y) v++, z += i.first;
        } else {
            w++, z += i.first;
        }
        if (u + v + w == x + y) break;
    }
    cout << z;
}
