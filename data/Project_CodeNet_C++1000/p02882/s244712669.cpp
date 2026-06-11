#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    double a, b, x;
    cin >> a >> b >> x;
    x /= a;

    double ans;
    if (x > a * b / 2)
        ans = atan2((a * b - x) * 2, a * a) * 180.0 / M_PI;
    else
        ans = atan2(b * b, x * 2) * 180.0 / M_PI;

    printf("%.10f\n", ans);
    return 0;
}
