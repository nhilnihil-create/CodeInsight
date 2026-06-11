#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^18 -> 18回
// double pi = M_PI or acos(-1)


int main() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;

    // 角度を求める
    double cAngle = 2 * M_PI * (((h + (double)m / 60) / 12) - (double)m / 60);
    double tmp = a * a + b * b - 2 * a * b * cos(cAngle);
    double ans = sqrt(tmp);

    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}
