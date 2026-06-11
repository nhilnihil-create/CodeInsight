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

const int N = 1e5 + 7;

int wa[N];
bool ac[N];

void solve() {
    int n, m;
    cin >> n >> m;
    loop(i, m) {
        int x; cin >> x;
        string s; cin >> s;
        if (s == "AC")
            ac[x] = 1;
        else if (!ac[x])
            ++wa[x];
    }
    int ans1 = 0, ans2 = 0;
    loop(i, N) {
        ans1 += ac[i];
        ans2 += (ac[i] ? wa[i] : 0);
    }
    cout << ans1 << " " << ans2;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}