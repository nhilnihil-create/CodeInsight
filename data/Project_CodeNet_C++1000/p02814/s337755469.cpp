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

ll gcd(ll a, ll b) {
    while (b) {
        ll c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    ll a[100005] = {}, g = 0, c[100005] = {};
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        a[i] /= 2;
        ll b = gcd(g, a[i]);
        if (!g) g = a[i];
        else g = g * a[i] / b;
        if (g > mod) g = mod;
    }
    for (int i = 0; i < n; i++) {
        while (a[i] % 2 == 0) a[i] /= 2, c[i]++;
    }
    for (int i = 1; i < n; i++) if (c[i] != c[i - 1]) {
        cout << 0;
        return 0;
    }
    ll z = m / g;
    if (z % 2) cout << z / 2 + 1;
    else cout << z / 2;
}
