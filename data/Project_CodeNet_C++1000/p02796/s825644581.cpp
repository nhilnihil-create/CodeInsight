#include <iostream>
#include <cmath>

#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_set>
#include <array>
#include <queue>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> l(n);
    vector<tuple<int, int, int>> intervals(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> l[i];
        intervals[i] = make_tuple(i,x[i] - l[i],  x[i] + l[i]);
    }
    sort(intervals.begin(), intervals.end(), [](tuple<int, int, int> x1, tuple<int, int, int> x2) {
        return get<2>(x1) < get<2>(x2);
    });
    int cnt  = 0;
    int idx = 0;
    while(idx < n) {
        auto interval = intervals[idx];
        ++idx;
        ++cnt;
        for (; idx < n; ) {
            if (get<2>(interval) > get<1>(intervals[idx])) {
                ++idx;
            } else {
                break;
            }
        }
    }
    cout << cnt << endl;
}
