#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
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

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x

signed main() {
    int n, k;
    cin >> n >> k;

    vector<double> vp;
    rep(i, n) {
        capi(p);
        vp.push_back((p + 1) / 2.0);
    }

    double res = 0.0;
    rep(j, k) {
        res += vp[j];
    }
    double ans = res;

    for (int i = 0; i + k < n; ++i) {
        res += vp[i + k];
        res -= vp[i];

        ans = max(ans, res);
    }

    printf("%.12lf", ans);

    return 0;
}