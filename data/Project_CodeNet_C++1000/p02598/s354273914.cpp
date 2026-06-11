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
    int n, k, a[200005] = {}, l = 0, r = mod;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    while (l + 1 < r) {
        int m = (l + r) / 2, c = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > m) c += (a[i] - 1) / m;
            c = min(c, mod);
        }
        if (c <= k) r = m;
        else l = m;
    }
    cout << r << '\n';
}
