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

const int INF = 1e12 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n), b(n);
    loop(i, n)
        cin >> a[i];
    loop(i, n)
        cin >> b[i];
    sort(all(a), greater<int>());
    sort(all(b));
    int l = -1, r = INF;
    while (r - l > 1) {
        int m = l + r >> 1;
        int d = 0;
        loop(i, n)
            d += max(0ll, a[i] - m / b[i]);
        if (d > k)
            l = m;
        else
            r = m;
    }
    cout << r;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
