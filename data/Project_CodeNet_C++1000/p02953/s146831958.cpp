#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    --h[0];
    for (int i = 1; i < n; ++i) {
        if (h[i] - 1 >= h[i - 1])
            --h[i];

        if (h[i] < h[i - 1]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
