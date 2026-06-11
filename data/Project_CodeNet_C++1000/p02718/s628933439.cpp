#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    double n, m;
    cin >> n >> m;

    vector<double> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    double s = accumulate(a.begin(), a.end(), 0);
    rep(i, m) {
        if(s / (4 * m) > a[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}