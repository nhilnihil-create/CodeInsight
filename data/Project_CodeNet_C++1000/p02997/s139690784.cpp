#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr ll inf = INT64_MAX / 4;
constexpr double pi = asin(1) * 2;
constexpr ll mod = 1000000007;


ll mpow(ll base, ll power) {
    if (power == 0) return 1;
    ll t = mpow(base, power / 2);
    return (t * t * (power % 2 ? base : 1)) % mod;
}

int main() {
    int n, k;
    cin >> n >> k;
    int m = ((n - 1) * (n - 2)) / 2;
    if (k > m) {
        cout << -1 << endl;
        return 0;
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n - 1; i++) {
        v.emplace_back(1, i + 2);
    }
    int c = m - k;
    for (int i = 2; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (c == 0) {
                i = j = n + 1;
                continue;
            }
            v.emplace_back(i, j);
            c--;
        }
    }
    cout << v.size() << '\n';
    for(auto&e:v) cout << e.first << ' ' << e.second << '\n';
}
