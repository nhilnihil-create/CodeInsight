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

    string s, s2;
    cin >> s;

    s2 = s;

    i64 ans{0};
    for (size_t i=0; i<n-1; ++i) {
        char first = 0;
        s2 = s2.substr(1);
        s2.push_back(first);

        i64 tmp = count_same(s,s2,i+1);
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}