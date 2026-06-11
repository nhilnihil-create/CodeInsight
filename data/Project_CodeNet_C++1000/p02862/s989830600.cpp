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
    ll x, y, f[2000006] = {1}, g[2000006] = {};
    for (int i = 1; i <= 2000000; i++) f[i] = f[i - 1] * i % mod;
    g[2000000] = 407182070;
    for (int i = 1999999; i >= 0; i--) g[i] = g[i + 1] * (i + 1) % mod;
    cin >> x >> y;
    if ((x + y) % 3) {
        cout << 0;
    } else if (x > y) {
        if (y + y < x) cout << 0;
        else {
            ll n = 0, m = 0, k = (x + y) / 3;
            for (int i = 0; i <= k; i++) {
                if (i + i + k - i == x && i + k - i + k - i == y) {
                    n = i;
                    m = k - i;
                    break;
                }
            }
            cout << f[k] * g[n] % mod * g[m] % mod;
        }
    } else {
        if (x + x < y) cout << 0;
        else {
            ll n = 0, m = 0, k = (x + y) / 3;
            for (int i = 0; i <= k; i++) {
                if (i + i + k - i == x && i + k - i + k - i == y) {
                    n = i;
                    m = k - i;
                    break;
                }
            }
            cout << f[k] * g[n] % mod * g[m] % mod;
        }
    }
}
