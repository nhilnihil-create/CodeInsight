#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define inf 1e9
#define INF 1000000000000000000

int main() {
    double a, b, x, ans;
    cin >> a >> b >> x;
    if (2 * x >= a * a * b) {
        double f = a, l = 2 * b - (2 * x) / (a * a);
        ans = atan2(l, f);
    } else {
        double f = b, l = (2 * x) / (a * b);
        ans = atan2(f, l);
    }

    ans = ans * 180 / M_PI;

    cout << fixed << setprecision(10) << ans << endl;
}