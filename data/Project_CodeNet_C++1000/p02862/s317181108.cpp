#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using vi = vector<int>;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

#define P (1'000'000'007)

inline int fast_pow(int x, int n, int mod) {
    long long signed res = 1;
    long long accumulation = x;
    for (int i = 0; n >> i > 0; ++ i) {
        if ((n >> i) % 2) {
            res *= accumulation;
            res %= mod;
        }
        accumulation *= accumulation;
        accumulation %= mod;
    }

    return res;
}

inline int fast_comb(int n, int r, int mod) {
    long long a = 1;
    long long b = 1;
    for (int i = 0; i < r; ++i) {
        a = a * (n - i) % mod;
        b = b * (i + 1) % mod;
    }

    b = fast_pow(b, mod - 2, mod);
    return a * b % mod;
}

signed main() {
    int x, y;
    cin >> x >> y;

    if ((x + y) % 3 == 0) {
        int c = (x + y) / 3;
        if (c <= x && x <= c * 2 && c <= y && y <= c * 2) {
            int t = 2 * c - x;
            cout << fast_comb(c, t, P);
        } else {
            cout << 0;
        }
    } else {
        cout << 0;
    }

    return 0;
}
