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
    int n, c = 0;
    ll a[100005] = {}, b = 0, z = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], b ^= a[i];
    for (int i = 0; i < n; i++) a[i] &= ~b;
    for (int i = 59; i >= 0; i--) {
        bool y = 0;
        for (int j = c; j < n; j++) if (a[j] & (1ll << i)) {
            if (j != c) a[c] ^= a[j];
            y = 1;
            break;
        }
        if (!y) continue;
        for (int j = c + 1; j < n; j++) if ((a[j] ^ a[c]) < a[j]) a[j] ^= a[c];
        c++;
    }
    for (int i = 0; i < n; i++) if ((z ^ a[i]) > z) z ^= a[i];
    cout << z + z + b;
}
