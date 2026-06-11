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
#define mkt make_tuple
#define no {cout << "No"; return;}

void solve() {
    int n, m, sum = 0;
    cin >> n >> m;
    vector <int> mns;
    loop(i, n) {
        int x; cin >> x;
        sum += x;
        while (x) {
            mns.pb(x - (x >> 1));
            x >>= 1;
        }
    }
    sort(all(mns), greater<int>());
    loop(i, min(m, (int)mns.size()))
        sum -= mns[i];
    cout << sum;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}