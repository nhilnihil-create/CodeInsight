#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int h, n;
    cin >> h >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.rbegin(), a.rend());
    rep(i, n) {
        h -= a[i];
        if (h <= 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}