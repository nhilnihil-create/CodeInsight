#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, D;
    cin >> M >> D;
    int res = 0;

    auto ok = [&](int m, int d) {
        string s = to_string(d);
        if (s.length() == 2) {
            int a = s[0] - '0';
            int b = s[1] - '0';
            if (a * b == m && a > 1 && b > 1) {
                return true;
            }
        }
        return false;
    };

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= D; ++j) {
            if (ok(i, j)) {
                ++res;
            }
        }
    }

    cout << res << '\n';
    return 0;
}