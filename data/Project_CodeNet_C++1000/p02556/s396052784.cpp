#include <iostream>
#include <set>
#include <algorithm>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    i64 ret = 0;
    std::multiset<i64> pp, pm, mp, mm;
    for (int i = 0; i < n; i++) {
        i64 x, y;
        std::cin >> x >> y;
        if (i) {
            const i64 max = std::max({
                x + y + *mm.rbegin(),
                x - y + *mp.rbegin(),
                -x + y + *pm.rbegin(),
                -x - y + *pp.rbegin(),
            });
            if (max > ret) ret = max;
        }
        pp.insert(x + y);
        pm.insert(x - y);
        mp.insert(-x + y);
        mm.insert(-x - y);
    }

    std::cout << ret << std::endl;

    return 0;
}
