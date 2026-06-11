#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <string>
#include <limits>

using namespace std;

using i64 = int64_t;
using P = pair<i64, i64>;
i64 mod = 1000000007;
//i64 mod = 998244353;
int int_max = 2147483647;
i64 INF = 1e16;
int max_n = 1e5;


int main(int argc, char **argv) {
    i64 n;
    cin >> n;

    vector<pair<i64, i64>> engines;
    vector<pair<double, i64>> rads;

    for (int i=0; i<n; ++i) {
        i64 x, y;
        cin >> x >> y;
        engines.push_back(make_pair(x, y));
        double r = atan2((double)y, (double)x);
        rads.push_back(make_pair(r, i));
    }

    for (int i=0; i<n; ++i) {
        rads.push_back(make_pair(rads[i].first + 2*M_PI, rads[i].second));
    }

    sort(rads.begin(), rads.end());

    double ans{0};
    for (int left=0; left<n; ++left) {
        i64 l_idx = rads[left].second;
        double sum_x=engines[l_idx].first, sum_y=engines[l_idx].second;
        ans = max(ans, sqrt(pow(sum_x,2) + pow(sum_y, 2)));
        for (int right=left+1; right<left+n; ++right) {
            i64 idx = rads[right].second;
            //if (l_rad + M_PI/2 < r_rad) break;
            sum_x += engines[idx].first; sum_y += engines[idx].second;

            ans = max(ans, sqrt(pow(sum_x,2) + pow(sum_y, 2)));
        }
    }

    cout << setprecision(15) << ans << endl;

    return 0;
}
