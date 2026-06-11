#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 2; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    int k = 0;
    REP(i, n) {
        if (a[i] != i + 1) {
            k++;
        }
    }
    if (k <= 2) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
 }