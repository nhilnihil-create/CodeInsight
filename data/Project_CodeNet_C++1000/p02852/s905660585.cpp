#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <complex>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>
#include <iterator>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;

int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> res;
    int r = n;
    for (int i = r, l = i; i >= 0; --i) {
        if (s[i] == '0') l = i;
        if (r - i == m || i == 0) {
            if (r == l) {
                cout << -1 << endl;
                return 0;
            }
            res.push_back(r - l);
            r = l;
        }
    }
    reverse(begin(res), end(res));
    for (int x : res) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}