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

int main() {
    int n, l;
    cin >> n >> l;
    int res = 0;
    int min_diff = 0x3f3f3f3f;
    int min_value = 0;
    for (int i = 1; i <= n; i++) {
        int t = l + i - 1;
        if (abs(t) < min_diff) {
            min_diff = abs(t);
            min_value = t;
        }
        res += t;
    }
    cout << res - min_value << endl;
}
