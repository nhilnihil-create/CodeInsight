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

ll a, b, n;
ll sum;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        sum += (i + 1) * (n - i);
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b; // [a, b]
        if (a > b)
            swap(a, b);
        sum -= a * (n - b + 1);
    }
    cout << sum << endl;
    return 0;
}
