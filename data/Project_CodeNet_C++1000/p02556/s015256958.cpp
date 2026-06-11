#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
long long a[200005], b[200005];

/*
 * |xi - xj| + |yi - yj|
 * 假设 xi > xj
 * xi - xj + yi - yj = (xi + yi) - (xj + yj)
 * 或
 * xi - xj + yj - yi = (xi - yi) - (xj - yj)
 */

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i] = x + y;
        b[i] = x - y;
    }
    sort(a, a + n);
    sort(b, b + n);
    cout << max(a[n - 1] - a[0], b[n - 1] - b[0]) << endl;
    return 0;
}
