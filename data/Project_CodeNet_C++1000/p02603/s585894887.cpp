#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& it : a)
        cin >> it;
    int j = 0;
    ll cash = 1000;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            cash += (ll)(a[i] - a[j]) * (cash / a[j]);
            j = i + 1;
        }
    }
    cash += (ll)(a[n - 1] - a[j]) * (cash / a[j]);
    cout << cash << '\n';
    return 0;
}