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
#define no {cout << 0; return;}
#define mkp make_pair
#define mkt make_tuple
#define cerr if(0) cerr

const int N = 2e5 + 7;

bool used[N];

void solve() {
    int n, k, r, s, p;
    string t;
    cin >> n >> k >> r >> s >> p >> t;
    int ans = 0;
    loop(i, t.size()) {
        char win = (t[i] == 'r' ? 'p' : (t[i] == 's' ? 'r' : 's'));
        char wink = (i < k || !used[i - k] ? 'y' : (t[i - k] == 'r' ? 'p' : (t[i - k] == 's' ? 'r' : 's')));
        if (win != wink) {
            ans += (win == 'r' ? r : (win == 's' ? s : p));
            used[i] = 1;
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
