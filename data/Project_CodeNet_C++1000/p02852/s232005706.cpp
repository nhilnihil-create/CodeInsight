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
#include <iterator>
#include <string>
#include <limits>

using namespace std;

using i64 = int64_t;
using P = pair<i64, i64>;
i64 mod = 1000000007;
int int_max = 2147483647;
i64 INF = 1e16;
int max_n = 1e5;


int main(int argc, char **argv) {
    i64 n,m;
    string s;
    cin >> n >> m >> s;
    std::vector<i64> leftest(n);
    i64 jump{1};
    leftest[0] = n;
    i64 left{n};
    while (true) {
        for (i64 i=left; i>=0&&i>=left-m; --i) {
            if (s[i] == '0') {
                leftest[jump] = i;
            }
        }
        if (leftest[jump] == leftest[jump-1]) {
            cout << -1 << endl;
            return 0;
        }
        left = leftest[jump];

        if (left==0) break;
        ++jump;
    }
    for (i64 j = jump; j > 0; --j) {
        cout << (leftest[j-1] - leftest[j]) << " ";
    }

    cout << endl;

    return 0;
}