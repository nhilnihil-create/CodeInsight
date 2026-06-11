#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const double pi = acos(-1);
long double f(long double a, long double b, long double x) {
    if(a * a * b / 2.0 <= x) return atan(2 * (a * a * b - x) / (a * a * a));
    else return pi / 2 - atan(2 * x / (a * b * b));
}
int main()
{
    Hello
    long double a, b, x;
    cin >> a >> b >> x;
    cout << fixed << setprecision(6) << f(a, b, x) * 180.0/pi;
    return 0;
}
