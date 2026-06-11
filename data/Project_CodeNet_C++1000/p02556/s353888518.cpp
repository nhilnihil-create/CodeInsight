#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> xpy, xmy;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        xpy.pb(x + y);
        xmy.pb(x - y);
    }
    sort(xpy.begin(), xpy.end());
    sort(xmy.begin(), xmy.end());
    cout << max(xpy.back() - xpy[0], xmy.back() - xmy[0]) << '\n';
    return 0;
}