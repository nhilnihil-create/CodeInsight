#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

void solve() {
    int n;
    cin >> n;
    cout << 10 - (n / 200) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    while (tt--)
        solve();
    return 0;
}
