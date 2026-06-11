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

int n;
int a[105];
int sum, sum2;
int main() {
    int res = 1e9;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; ++i) {
        sum2 += a[i];
        res = min(res, abs(sum - sum2 * 2));
    }
    cout << res << endl;
    return 0;
}