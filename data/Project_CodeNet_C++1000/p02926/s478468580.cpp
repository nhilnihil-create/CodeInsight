#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <chrono>
#include <stack>
#include <string>
#include <bitset>
#include <unordered_map>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <unordered_set>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define ll long long
#define sz(x) (int)(x.size())
#define pb push_back
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define endl "\n"
#define int long long


const int N = (int)(1e6) + 322;
const long long inf = (long long)(1e18) + 123;
const int mod = (int)(1e9);
const double EPS = 1e-9;


int n, x[N], y[N];

inline int dot(int i, int j) {
    return x[i] * x[j] + y[i] * y[j];
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            int curx = 0, cury = 0;
            for(int k = 1; k <= n; ++k) {
                if (dot(i, k) > 0 || dot(j, k) > 0) {
                    curx += x[k];
                    cury += y[k];
                }
            }
            //cout << i << ' ' << j <<
            ans = max(ans, curx * curx + cury * cury);
        }
    }
    cout << setprecision(10) << fixed << sqrt(ans);
    return 0;
}

