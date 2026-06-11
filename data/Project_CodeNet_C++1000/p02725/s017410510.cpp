#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int k, n; cin >> k >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;

    int dis = 0;
    for (int i = 0; i < n - 1; ++i) {
        dis = max(dis, abs(a[i] - a[i + 1]));
    }

    dis = max(dis, a.front() + (k - a.back()));
    cout << k - dis << endl;
}

