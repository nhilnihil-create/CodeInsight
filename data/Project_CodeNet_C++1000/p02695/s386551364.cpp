#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int n, m, q;
int res = 0;
vector<vector<int>> v;
vector<int> nums;

void f() {
    if (nums.size() == n + 1) {
        int r = 0;
        for (auto item : v) {
            if (nums[item[1]] - nums[item[0]] == item[2]) {
                r += item[3];
            }
        }
        res = max(res, r);
        return;
    }
    for (int i = nums.back(); i <= m; i++) {
        nums.push_back(i);
        f();
        nums.pop_back();
    }
}

int main() {        
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({a, b, c, d});
    }
    nums.push_back(1);
    for (int i = 1; i <= m; i++) {
        nums.push_back(i);
        f();
        nums.pop_back();
    }
    cout << res << endl;
}
