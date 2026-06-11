#include <iostream>
#include <cmath>

#include <vector>
#include <algorithm>
#include <limits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <queue>

typedef long long ll;

using namespace std;


int main() {
    int n;
    cin >> n;
    ll a = 1, b = 1, c = 1;
    ll m = pow(10, 9) + 7;
    for (int i = 0; i < n; ++i) {
        a = (10 * a) % m;
        b = (9 * b) % m;
        c = (8 * c) % m;
    }
    ll ans = (((a + c) % m) - ((2 * b) % m)) % m;
    if (ans < 0) {
        ans += m;
    }
    cout << ans << endl;
}
