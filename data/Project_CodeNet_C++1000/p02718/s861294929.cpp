#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int n, m, sum = 0;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.rbegin(), a.rend());
    if (a[m - 1] >= sum / (4.0 * m)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}