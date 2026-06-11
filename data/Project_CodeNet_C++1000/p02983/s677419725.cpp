#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdint>
using namespace std;

int main() {
    int l, r; cin >> l >> r;

    if (l <= r / 2019 * 2019) {
        cout << 0 << endl;
        return 0;
    }

    int64_t ans = INT_MAX;
    for (int64_t i = l; i < r; ++i) {
        for (int64_t j = i + 1; j <= r; ++j) {
            ans = min(ans, i * j % 2019);
        }
    }

    cout << ans << endl;

    // 45 * 46 % 2019 = 51
    // 8 * 9 % 2019 = 72
    // のため、2019を倍数に含まない数列に対してでも左から2個取ったものが最適解とは限らない
    //cout << ((l % 2019) * ((l + 1) % 2019) % 2019) << endl;
}

