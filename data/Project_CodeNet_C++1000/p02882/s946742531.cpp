#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll a, b, x;
    cin >> a >> b >> x;

    long double v = (long double)pow(a, 2) * b;

    long double tan;
    if (v < 2 * x)
    {
        tan = (v - x) / pow(a, 3) * 2;
    }
    else
    {
        tan = (long double)a * pow(b, 2) / x / 2;
    }

    long double theta = atan(tan);
    long double ans = 180 * theta / M_PI;

    cout << setprecision(7) << ans << endl;
    return 0;
}