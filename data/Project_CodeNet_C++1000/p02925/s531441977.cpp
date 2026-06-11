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
#define no {cout << -1; return;}

const int N = 1007;

queue <int> q[N];

void solve() {
    int n; cin >> n;
    loop1(i, n) {
        loop(j, n - 1) {
            int x; cin >> x;
            q[i].push(x);
        }
    }
    bool ok = 1;
    int ans = 0;
    while (ok) {
        ok = 0; ++ans;
        vector <int> del;
        loop1(i, n)
            if (!q[i].empty()) {
                ok = 1;
                if (i == q[q[i].front()].front())
                    del.pb(i);
            }
        if (ok && del.empty())
            no;
        for (int x : del)
            q[x].pop();
    }
    cout << ans - 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}