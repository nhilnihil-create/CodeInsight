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
    int w, h, x, y;
    cin >> w >> h >> x >> y;
    cout << 0.5 * w * h << " ";
    if (2 * x == w && 2 * y == h) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}
