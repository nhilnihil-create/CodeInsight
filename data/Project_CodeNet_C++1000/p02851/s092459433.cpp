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

const int N = 2e5 + 7;

int a[N], p[N];
map <int, int> c, cp;

void solve() {
    int n, k;
    cin >> n >> k;
    loop1(i, n) {
        cin >> a[i];
        p[i] = (p[i - 1] + a[i]) % k;
    }
    int ans = 0;
    loop(i, n + 1) {
        ans += c[p[i] - i] + cp[p[i] - i];
        ++c[p[i] - i]; ++cp[p[i] - i - k];
        if (i >= k - 1) {
            int pos = p[i - (k - 1)] - (i - (k - 1));
            --c[pos]; --cp[pos - k];
        }
    }
    cout << ans;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
