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


int main(int argc, char **argv) {
    i64 h,w,m;
    cin >> h >>w >>m;

    unordered_map<i64,unordered_set<i64>> hw;
    unordered_map<i64, i64> h_map, w_map;
    for (int i=0; i<m; ++i) {
        i64 h1,w1;
        cin >> h1 >> w1;
        auto it = h_map.find(h1);
        if (it==h_map.end()) {
            h_map[h1] = 1;
            hw[h1] = unordered_set<i64>();
        } else {
            ++h_map[h1];
        }

        auto it2 = w_map.find(w1);
        if (it2==w_map.end()) {
            w_map[w1] = 1;
        } else {
            ++w_map[w1];
        }
        hw[h1].insert(w1);
    }
    i64 w_max{0}, h_max{0};
    vector<i64> w_max_v, h_max_v;
    for (auto kv : h_map) {
        if (kv.second > h_max) {
            h_max = kv.second;
            h_max_v.clear();
            h_max_v.push_back(kv.first);
        } else if (kv.second == h_max) {
            h_max_v.push_back(kv.first);
        }
    }
    for (auto kv : w_map) {
        if (kv.second > w_max) {
            w_max = kv.second;
            w_max_v.clear();
            w_max_v.push_back(kv.first);
        } else if (kv.second == w_max) {
            w_max_v.push_back(kv.first);
        }
    }
    bool br{false};
    for (i64 hm : h_max_v) {
        for (i64 wm: w_max_v) {
            if (hw.find(hm) == hw.end() ||
                    hw[hm].find(wm) == hw[hm].end()) {
                br = true;
                break;
            }
        }
        if (br) break;
    }
    i64 ans = w_max + h_max - (br?0:1);

    cout << ans << endl;

    return 0;
}