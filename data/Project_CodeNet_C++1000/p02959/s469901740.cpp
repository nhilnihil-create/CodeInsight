#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, b;
    cin >> n;
    vector<int> a(n+1);
    ll ans = 0;

    for (int i = 0; i <= n; i++) {
        cin >> a.at(i);
    }

    for (int i = 0; i < n; i++) {
        cin >> b;
        if (a.at(i) < b) {
            ans += a.at(i);
            b -= a.at(i);
            if (a.at(i+1) < b) {
                ans += a.at(i+1);
                a.at(i+1) = 0;
            } else {
                ans += b;
                a.at(i+1) -= b;
            }
        } else {
            ans += b;
        }
    }
    cout << ans << endl;
    return 0;
}