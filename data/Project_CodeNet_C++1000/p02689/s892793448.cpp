// 基本のinclude
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define invrep(i,n) for(int i = (int)(n); i > 0; i++)
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    ll h[n];
    rep(i, n) cin >> h[i];
    int a[m], b[m];
    rep(i, m) cin >> a[i] >> b[i];

    int good[n];
    rep(i, n) good[i] = 1;

    rep(i, m) {
        if (h[a[i]-1] - h[b[i]-1] <= 0) good[a[i]-1] = 0;
        if (h[b[i]-1] - h[a[i]-1] <= 0) good[b[i]-1] = 0;
    }

    int ans = 0;
    rep(i, n) ans += good[i];

    cout << ans << endl;
    return 0;
}