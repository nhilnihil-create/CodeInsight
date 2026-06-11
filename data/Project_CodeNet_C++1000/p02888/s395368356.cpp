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

void solve() {
    int n; cin >> n;
    vector <int> a(n);
    loop(i, n)
        cin >> a[i];
    sort(all(a));
    int ans = 0;
    loop(i, n) {
        loop(j, i) {
            int r = upper_bound(all(a), a[i] + a[j] - 1) - a.begin(), l = lower_bound(all(a), abs(a[i] - a[j]) + 1) - a.begin();
            ans += r - l - (l <= i && r > i) - (l <= j && r > j);
        }
    }
    cout << ans / 3;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
