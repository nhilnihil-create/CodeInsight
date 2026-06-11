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
#define mkt make_tuple
#define no {cout << "No"; return;}

void solve() {
    int n; cin >> n;
    vector <int> a(n), b(n), c(n);
    loop(i, n) {
        cin >> a[i];
        --a[i];
    }
    loop(i, n)
        cin >> b[i];
    loop(i, n - 1)
        cin >> c[i];
    int ans = 0;
    loop(i, n)
        ans += b[a[i]] + (i && a[i] == a[i - 1] + 1 ? c[a[i] - 1] : 0);
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}