#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;
    vector<int> pi(n);
    rep(i, n) cin >> pi.at(i);

    int cnt = 0;
    rep(i, n - 2) {
        if ((pi.at(i) < pi.at(i + 1) && pi.at(i + 1) < pi.at(i + 2)) ||
            (pi.at(i) > pi.at(i + 1) && pi.at(i + 1) > pi.at(i + 2))) {
            cnt++;
        }
    }
    cout << cnt << endl;
}