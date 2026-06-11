#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <climits>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main()
{
    int M, D;
    cin >> M >> D;

    int ans = 0;

    for (int m = 1; m <= M; ++m) {
        for (int d = 1; d <= D; ++d) {
            int d1 = d % 10;
            int d10 = d / 10;

            if (d1 >= 2 && d10 >= 2 && d1 * d10 == m) {
                ++ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
