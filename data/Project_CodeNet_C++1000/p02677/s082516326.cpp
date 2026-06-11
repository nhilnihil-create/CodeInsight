#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const double PI = acos(-1);

int main()
{
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    double th = double(60*h+m)/720 * 2 *PI;
    double tm = double(m)/60 * 2*PI;
    double ac = a*cos(th);
    double as = a*sin(th);
    double bc = b*cos(tm);
    double bs = b*sin(tm);
    double ans = (ac-bc)*(ac-bc) + (as-bs)*(as-bs);
    printf("%.20f\n", sqrt(ans));
    return 0;
}