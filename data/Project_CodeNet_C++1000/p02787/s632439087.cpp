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

ll sol(ll n) {
    if (n == 1) return 1;
    return sol(n / 2) * 2 + 1;
}

int main() {
    ios::sync_with_stdio(false);
    int h, n, a[1003] = {}, b[1003] = {}, d[20004] = {}, z = mod;
    cin >> h >> n;
    for (int i = 1; i <= 20000; i++) d[i] = mod;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= 20000; j++) d[j] = min(d[j], d[j - a[i]] + b[i]);
    }
    for (int i = h; i <= 20000; i++) z = min(z, d[i]);
    cout << z;
}
