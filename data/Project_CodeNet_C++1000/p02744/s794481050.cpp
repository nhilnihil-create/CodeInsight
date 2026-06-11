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
int max_n = 1e5;
using mat2d_t = std::vector<std::vector<int64_t>>;

void dfs(set<std::string>& m, std::string str, char mx, const int N) {
    if (str.size() >= N)  {
        m.insert(str);
        return;
    }

    for (char c=mx; c >= 'a'; --c) {
        string tmp = str + c;
        dfs(m, tmp, c == mx ? (mx+1): mx, N);
    }
}

int main(int argc, char **argv) {
    int n;
    cin >> n;

    set<std::string> ans;

    dfs(ans, "", 'a', n);

    for (auto s : ans) {
        cout << s << endl;
    }

    return 0;
}
