#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define int long long

signed main() {
    int h, w, n;
    cin >> h >> w >> n;

    cout << ceil(n * 1.0 / max(h, w)) << endl;
    return 0;
}