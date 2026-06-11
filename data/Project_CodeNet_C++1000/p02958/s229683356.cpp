#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int n, t, cnt;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        if (t > i) {
            cnt++;
        }
    }
    if (cnt > 1)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
