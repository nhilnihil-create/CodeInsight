#include <math.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define rep(inc, bgn, end) for (int inc = bgn; inc < end; ++inc)
#define repe(inc, bgn, end) for (int inc = bgn; inc <= end; ++inc)

using ll = long long;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> val(n, 0);
    rep(i, 0, n) {
        cin >> val[i];
    }
    sort(val.begin(), val.end());
    int ans = 0;
    rep(i, 0, k) {
        ans += val[i];
    }
    cout << ans;
    return 0;
}
