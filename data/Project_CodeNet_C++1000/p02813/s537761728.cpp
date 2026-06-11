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
    int n, a[8] = {}, b[8] = {}, c[8] = {1, 2, 3, 4, 5, 6, 7, 8}, x = 0, y = 0, z = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    do {
        bool u = 0, v = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != c[i]) u = 1;
            if (b[i] != c[i]) v = 1;
        }
        if (!u) x = z;
        if (!v) y = z;
        z++;
    } while (next_permutation(c, c + n));
    cout << abs(x - y);
}
