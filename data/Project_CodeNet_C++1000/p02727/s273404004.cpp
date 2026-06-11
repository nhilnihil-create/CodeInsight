#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define debug(x) (cout << # x ": " << x << endl)
#define int long long int
#define repeat(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()

signed main() {
    int x, y, a, b ,c;
    cin >> x >> y >> a >> b >> c;

    vector<int> va, vb, vc;
    repeat(i, a) {
        int x;
        cin >> x;
        va.push_back(x);
    }
    repeat(i, b) {
        int x;
        cin >> x;
        vb.push_back(x);
    }
    repeat(i, c) {
        int x;
        cin >> x;
        vc.push_back(x);
    }

    sort(all(va), std::greater());
    sort(all(vb), std::greater());

    repeat(i, a - x) {
        va.pop_back();
    }
    repeat(i, b - y) {
        vb.pop_back();
    }

    vector<int> v;
    for (auto x: va) {
        v.push_back(x);
    }
    for (auto x: vb) {
        v.push_back(x);
    }
    for (auto x: vc) {
        v.push_back(x);
    }

    int ans = 0;

    sort(all(v), greater());
    auto it = v.begin();
    repeat(i, x + y) {
        ans += *it;
        ++it;
    }

    cout << ans;
    
    return 0;
}
