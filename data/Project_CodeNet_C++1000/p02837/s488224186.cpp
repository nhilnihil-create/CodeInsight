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
    int n, m[15] = {}, a[15][15] = {}, u, v, z = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m[i];
        for (int j = 0; j < m[i]; j++) {
            cin >> u >> v;
            if (v == 1) a[i][u - 1] = 1;
            else a[i][u - 1] = -1;
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        int b[15] = {};
        for (int j = 0; j < n; j++) if (i & (1 << j)) b[j] = 1;
        bool y = 0;
        for (int j = 0; j < n; j++) if (b[j]) {
            for (int k = 0; k < n; k++) {
                if (a[j][k] == 1 && !b[k]) {
                    y = 1;
                }
                if (a[j][k] == -1 && b[k]) {
                    y = 1;
                }
            }
        }
        if (!y) z = max(z, __builtin_popcount(i));
    }
    cout << z;
}
