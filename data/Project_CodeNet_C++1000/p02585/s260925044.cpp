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
    int n, k, p[5003] = {}, d[5003] = {};
    ll c[5003] = {}, e[5003] = {}, s = 0, z = -mod;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) {
        int b = p[i];
        d[i] = 1;
        e[i] = c[i];
        while (b != i) e[i] += c[b], b = p[b], d[i]++;
    }
    for (int i = 1; i <= n; i++) {
        if (e[i] < 0) {
            ll t = 0;
            int b = i;
            for (int j = 1; j <= min(d[i], k); j++) t += c[b], z = max(z, t), b = p[b];
        } else {
            ll t = 0;
            int b = i;
            for (int j = 1; j <= d[i]; j++) {
                t += c[b];
                if (j <= k % d[i]) z = max(z, t + e[i] * (k / d[i]));
                else z = max(z, t + e[i] * (k / d[i] - 1));
                b = p[b];
            }
        }
    }
    cout << z;
}
