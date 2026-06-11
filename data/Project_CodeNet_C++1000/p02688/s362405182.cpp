#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using ul = uint32_t;
using ull = uint64_t;
using namespace std;

int main() {
    fastIO;

    int n, k, d;
    cin >> n >> k;

    vector<bool> ate(101);
    for (int i = 1; i <= k; i++) {
        cin >> d;
        for (int j = 0; j < d; j++) {
            int a;
            cin >> a;
            ate[a] = true;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (ate[i] == false)
            cnt++;
    }
    cout << cnt << endl;
}