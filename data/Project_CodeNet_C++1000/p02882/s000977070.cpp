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

#define int ll
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
#define no {cout << -1; return;}
#define yes {cout << "Yes"; return;}
#define mkp make_pair
#define mkt make_tuple
#define cerr if(0) cerr

const double PI = 3.14159265359, eps = 1e-8;

double len(double base, double v, double angle) {
    double trngl = base * base / (tan(angle) * 2);
    if (trngl > v)
        return sqrt(2 * v / tan(angle));
    return base / tan(angle) + (v - trngl) / base;
}

void solve() {
    double a, b, x;
    cin >> a >> b >> x;
    x /= a;
    double l = 0, r = PI / 2;
    while (r - l > eps) {
        double m = (l + r) / 2;
        if (len(a, x, m) > b)
            l = m;
        else
            r = m;
    }
    cout << fixed << setprecision(7) << 90 - l / PI * 180;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
