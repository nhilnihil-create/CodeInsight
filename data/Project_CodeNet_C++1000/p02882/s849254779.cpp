#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

/**
 * 弧度法表記を度数法表記に変換する
 * @param r 角度[rad]
 * @return  角度[deg]
 */
long double to_deg(long double r) {
    return r * 180.0 / (atanl(1.0) * 4.0);
}

int main() {
    long double a, b, x;
    cin >> a >> b >> x;
    
    long double ans = 0;
    if (x >= a * a * b / 2.0)
    {
        ans = to_deg(atanl(2.0 * b / a - 2.0 * x / (a * a * a)));
    } else
    {
        ans = to_deg(atanl(a * b * b / 2.0 / x));
    }
    
    cout << fixed << setprecision(10) << ans << endl;
    

  return 0;
}
