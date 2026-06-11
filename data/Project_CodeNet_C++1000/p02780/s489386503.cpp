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
#define no {cout << "NO\n"; return;}
#define yes {cout << "YES\n"; return;}
#define mkp make_pair
#define mkt make_tuple
#define cerr if(0) cerr

const int N = 2e5 + 7;

int a[N];

void solve() {
    int n, k; 
    cin >> n >> k;
    loop(i, n)
        cin >> a[i];
    int cur = 0;
    int L = 0;
    loop(i, k)
        cur += a[i] + 1;
    int ans = cur;
    while (L + k < n) {
        cur -= a[L] + 1;
        cur += a[L + k] + 1;
        ++L; ans = max(ans, cur);
    }
    cout << ans / 2 << (ans % 2 ? ".5" : ".0");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}