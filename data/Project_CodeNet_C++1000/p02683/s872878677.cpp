#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int n, m, x;
int c[12], a[12][12];

int main()
{
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int all = 1 << n;
    int mincost = INT_MAX;
    for (int mask = 0; mask < all; mask++) {
        int cost = 0;
        vector<int> level(m);
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                cost += c[i];
                for (int j = 0; j < m; j++)
                    level[j] += a[i][j];
            }
        }
        bool ok = true;
        for (int j = 0; j < m; j++) {
            if (level[j] < x) ok = false;
        }
        if (ok) {
            mincost = min(mincost, cost);
        }
    }
    if (mincost == INT_MAX)
        cout << -1 << endl;
    else
        cout << mincost << endl;
    return 0;
}