#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    int n, x;
    cin >> n >> x;
    vector<int> L(n);
    rep(i, n) cin >> L.at(i);

    int Di = 0;
    int cnt = 1;
    rep(i, n) {
        Di = Di + L.at(i);
        if (Di <= x)
            cnt++;
    }
    cout << cnt << endl;
}
