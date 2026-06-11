#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, m, d[3003][3003] = {}, z = 0;
    pii a[3003] = {};
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = a[i].first; j <= m; j++) {
            d[i][j] = max(d[i - 1][j], d[i - 1][j - a[i].first] + a[i].second);
        }
    }
    for (int i = 1; i <= n; i++) {
        int b = 0;
        for (int j = i + 1; j <= n; j++) b = max(b, a[j].second);
        z = max(z, d[i][m - 1] + b);
    }
    cout << z;
}
