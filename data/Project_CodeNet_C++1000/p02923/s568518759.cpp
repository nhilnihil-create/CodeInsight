#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int n, ans = 0, tmp = 0;
    cin >> n;
    vector<int> h(n);
    rep(i, n) { cin >> h[i]; }
    reverse(h.begin(), h.end());
    for (int i = 1; i < n; ++i) {
        if (h[i - 1] <= h[i])
            tmp++;
        else
            tmp = 0;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}