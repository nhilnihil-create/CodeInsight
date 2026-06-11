#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;

int main(){
    int n; cin >> n;
    long a[n+1], b[n], ans=0.0;
    rep(i, n + 1) {
        cin >> a[i];
    }
    rep(i, n) cin >> b[i];
    rep (i, n) {
        if(b[i] == 0) continue;

        if (b[i] <= a[i]) {
            ans += b[i];
            continue;
        }

        if (b[i] <= a[i] + a[i+1]) {
            ans += b[i];
            b[i] -= a[i];
            a[i+1] -= b[i];
            continue;
        }

        ans += a[i] + a[i+1];
        a[i+1] = 0;
    }
    cout << ans << endl;

    return 0;
}