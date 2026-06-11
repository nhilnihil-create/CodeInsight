#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    int n, k;
    cin >> n >> k;

    vector<int> H(n);
    rep(i, n) cin >> H.at(i);
    int cnt = 0;
    for (auto h : H) {
        if (h >= k)
            cnt++;
    }
    cout << cnt << endl;
}