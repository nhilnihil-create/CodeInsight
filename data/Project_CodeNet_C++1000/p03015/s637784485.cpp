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

string l;
int cnt, s[110000];

ll mpow(ll base, ll power) {
    if (power == 0) return 1;
    ll t = mpow(base, power / 2);
    return (t * t * (power % 2 ? base : 1)) % mod;
}

int main() {
    cin >> l;
    ll r = 0, n = l.length();
    for (auto &e:l)if (e == '1') cnt++;
    for (int i = 1; i < n; i++) {
        s[i] = s[i - 1] + (l[i - 1] == '1' ? 1 : 0);
    }
    for (int i = 0; i < n; i++) {
        if (l[i] == '1') {
            r = (r + mpow(3, n - (i + 1)) * mpow(2, s[i])) % mod;
        }
    }
    r = (r + mpow(2, cnt)) % mod;
    cout << r << endl;
}
