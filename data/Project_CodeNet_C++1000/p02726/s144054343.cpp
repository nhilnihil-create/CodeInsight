#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define debug(x) (cout << # x ": " << x << endl)
#define int long long int
#define repeat(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()

signed main() {
    int n, x, y;
    cin >> n >> x >> y;

    int a[2001];
    memset(a, 0, sizeof(int) * 2001);
    repeat(i, n) {
        int k = i + 1;
        for (int j = k + 1; j <= n; ++j) {
            int d = min(j - k, abs(x - k) + 1 + abs(y - j));
            ++a[d];
        }
    }

    repeat(i, n - 1) {
        cout << a[i + 1] << endl;
    }
    
    return 0;
}