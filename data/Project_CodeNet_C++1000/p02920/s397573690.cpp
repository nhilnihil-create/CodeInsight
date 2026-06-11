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
    vector <int> s(1 << n);
    loop(i, (1 << n))
        cin >> s[i];
    sort(all(s), greater<int>());
    vector <bool> used(1 << n), pused(1 << n);
    pused[0] = 1;
    loop(i, n) {
        int L = 0, R = 0;
        while (L < (1 << n)) {
            while (R < (1 << n) && (s[L] == s[R] || pused[R]))
                ++R;
            if (R == (1 << n))
                no;
            used[L] = used[R] = 1; ++R; ++L;
            while (L < (1 << n) && !pused[L])
                ++L;
        }
        pused = used;
    }
    cout << "Yes";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}