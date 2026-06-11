#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, m, a[3003] = {}, p[3003] = {1};
    ll e[3003][3003] = {};
    for (int i = 1; i <= 3000; i++) p[i] = p[i - 1] * 2 % 998244353;
    cin >> n >> m;
    e[0][0] = 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            e[i][j] = e[i - 1][j] * 2 % 998244353;
            if (j >= a[i]) e[i][j] = (e[i][j] + e[i - 1][j - a[i]]) % 998244353;
            //cout << e[i][j] << " \n"[j == m];
        }
    }
    cout << e[n][m];
}
