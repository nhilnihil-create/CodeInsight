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

i64 count_same(const string& lhs, const string& rhs, size_t shift) {
    i64 ret{0}, tmp{0};
    for (size_t i=0; i<lhs.size(); ++i) {
        if (lhs[i] == rhs[i]) ++tmp;
        else {
            ret = max(ret, tmp);
            tmp = 0;
        }
        if (tmp >= shift) return shift;
    }
    ret = max(ret, tmp);
    return ret;
}

int main(int argc, char **argv) {
    i64 n;
    cin >> n;

    vector<vector<i64>> input(n, vector<i64>(n-1, 0));
    vector<vector<i64>::const_iterator> active(n);

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n-1; ++j) {
            int k;
            cin >> k;
            input[i][j] = --k;
        }
        active[i] = input[i].begin();
    }
    i64 days{0};
    while (true) {
        bool end_flag{true};
        bool bad_flag{true};
        vector<bool> day_flag(n, false);
        for (int i=0; i<n; ++i) {
            if (day_flag[i]) continue;
            if (active[i] == input[i].end()) {
                continue;
            }
            end_flag = false;
            i64 cp = *(active[i]);
            if (*(active[cp]) == i && !day_flag[cp]) {
                ++(active[i]); ++(active[cp]);
                day_flag[i]=true; day_flag[cp]=true;
                bad_flag = false;
            }
        }
        if (end_flag) break;
        if (bad_flag) {
            cout << -1 << endl;
            return 0;
        }
        ++days;
    }

    cout << days << endl;

    return 0;
}