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

int n, t[200005];

void inc(int x, int v) {
    t[x += n] = v;
    for (x >>= 1; x; x >>= 1) t[x] = min(t[x << 1], t[x << 1 | 1]);
}

int que(int l, int r) {
    int z = mod;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) z = min(z, t[l++]);
        if (r & 1) z = min(z, t[--r]);
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    int m, d[100005] = {};
    string s;
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++) d[i] = mod, inc(i, mod);
    for (int i = n - 1; i >= 0; i--) if (s[i] == '0') {
        if (i + m >= n) d[i] = 1;
        else d[i] = que(i + 1, i + m + 1) + 1;
        inc(i, d[i]);
    }
    if (d[0] >= mod) {
        cout << -1;
        return 0;
    }
    int c = 0;
    while (c < n) {
        for (int i = c; ; i++) if (d[c] == d[i] + 1) {
            cout << i - c << ' ';
            c = i;
            break;
        }
    }
}
