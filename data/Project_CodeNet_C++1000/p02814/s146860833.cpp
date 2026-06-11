#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <numeric>
#include <ctime>
#include <complex>
#include <bitset>
#include <random>
#include <climits>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;

//#define int ll
#define double ld
#define loop(i, n) for(int i = 0; i < (int)n; ++i)
#define loop1(i, n) for(int i = 1; i <= (int)n; ++i)
#define F first
#define S second
#define pb push_back
#define pi pair <int, int>
#define all(x) begin(x), end(x)
#define ti tuple <int, int, int>
#define Point Vect
#define no {cout << 0; return;}
#define mkp make_pair
#define mkt make_tuple
#define cerr if(0) cerr

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n, m; 
    cin >> n >> m;
    int two = -1;
    ll cur = 1;
    bool ok = 1;
    loop(i, n) {
        int x; cin >> x;
        x >>= 1;
        int ctwo = 0, xx = x;
        while (!(xx & 1)) {
            xx >>= 1; ++ctwo;
        }
        if (two != -1 && ctwo != two)
            ok = 0;
        two = ctwo;
        cur = cur * x / gcd(cur, x);
        if (cur > m)
            ok = 0;
    }
    if (!ok) {
        cout << 0; return;
    }
    int l = 0, r = m + 1;
    while (r - l > 1) {
        int mid = l + r >> 1;
        if (cur * mid <= m)
            l = mid;
        else
            r = mid;
    }
    cout << r / 2;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
