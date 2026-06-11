#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <chrono>
#include <string>
#include <bitset>
#include <cassert>
#include <queue>
#include <memory>

//#pragma comment(linker, "/STACK:16777216")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("unswitch-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,abm,mmx,avx,avx2,popcnt,tune=native")

using namespace std;

//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define ll long long
#define ull unsigned long long
//#define double long double
//#define int ll
//#define int ull
//#define int short
//#define int unsigned short
//#define int unsigned int
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>
#define hash hash228
#define get get228
const int SZ = 1e2 + 4;
const double EPS = 1e-7;
const int mod = 998244353;
const int hashpow = 127;
const int inf = 2e9;

#define kek cout << "kek"

int n, a, b, c, d;
string s;

void read() {
    cin >> n >> a >> b >> c >> d >> s;
    --a, --b, --c, --d;
}

void solve() {
    if (c > d) {
        bool z = false;
        for (int i = b - 1; i <= min(d - 1, n - 3); ++i) {
            if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.') {
                z = true;
                break;
            }
        }
        if (!z) {
            cout << "No\n";
            return;
        }
        for (int i = a; i < c; ++i) {
            if (s[i] == '#' && s[i + 1] == '#') {
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
    }
    else {
        for (int i = a; i < d; ++i) {
            if (s[i] == '#' && s[i + 1] == '#') {
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //    int t;
    //    cin >> t;
    //    for (int i = 0; i < t; ++i) {
    read();
    solve();
    //    }

    return 0;
}