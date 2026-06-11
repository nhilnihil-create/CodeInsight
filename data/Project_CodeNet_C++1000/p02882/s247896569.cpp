#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

ll mod = 1000000007;

signed main()
{
    int a, b, x;
    cin >> a >> b >> x;
    double ratio = 1.0 * x / a / a / b;
    if (ratio > 0.5)
    {
        double ans = atan(2.0 / a / a / a * (a * a * b - x)) * 180.0 / 3.14159265358979;
        printf("%.10f\n", ans);
    }
    else
    {
        double ans = atan(1.0 / (2.0 * x / b / b / a)) * 180.0 / 3.14159265358979;
        printf("%.10f\n", ans);
    }
    return 0;
}