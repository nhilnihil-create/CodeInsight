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
#define ti tuple <int, int, int, int>
#define Point Vect
#define no {cout << "0\n"; return;}
#define mkp make_pair
#define cerr if (0) cerr

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    cout << (n >= b - 1 ? a * (b - 1) / b : a * n / b);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}