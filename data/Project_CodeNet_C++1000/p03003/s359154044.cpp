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
    const int mod = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    vector<int> vs(n + 1, 0), vt(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> vs[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> vt[i];
    }

    vector<vector<long long int>> res(n + 1, vector<long long int> (m + 1, 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vs[i] == vt[j]) {
                res[i][j] = (res[i - 1][j] + res[i][j - 1] - res[i - 1][j - 1]) + res[i - 1][j - 1];
            } else {
                res[i][j] = (res[i][j - 1] + res[i - 1][j] - res[i - 1][j - 1]);
            }            
            res[i][j] %= mod;
            res[i][j] += mod;
            res[i][j] %= mod;
        }
    }
    cout << res[n][m] << endl;
}
