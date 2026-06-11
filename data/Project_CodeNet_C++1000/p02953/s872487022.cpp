#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
    int n;
    cin >> n;
    int prev = -1e9;
    bool ok = true;
    vector<int> h(n);
    rep(i,n) cin >> h.at(i);
    for (int i = n-1; 1 <= i; --i) {
        if (h.at(i) >= h.at(i-1)) continue;
        h.at(i-1)--;
        if (h.at(i) < h.at(i-1)) ok = false;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
