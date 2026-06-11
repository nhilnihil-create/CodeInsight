#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    double n;
    cin >> n;
    vector<int> a(n);
    double bunsi = 1;
    double bunbo = 0;
    rep(i, n) cin >> a[i];
    rep(i, n) {
        double tmp = 1;
        rep(j, n) {
            if(i != j)
                tmp *= a[j];
        }
        bunbo += tmp;
        bunsi *= a[i];
    }
    // cout << "bunsi:" << bunsi << ",bunbo:" << bunbo << endl;
    cout << fixed << setprecision(5) << bunsi / bunbo << endl;
    return 0;
}