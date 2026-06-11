#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    int n, l;
    cin >> n >> l;

    bool zero = false;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (l + i);
        if (l + i == 0)
            zero = true;
    }

    if (zero)
        cout << sum;
    else {
        if (sum < 0) {
            cout << sum - (l + n - 1);
        } else {
            cout << sum - l;
        }
    }
}
