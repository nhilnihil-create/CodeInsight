#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, x;
    cin >> a >> b >> x;
    cout << fixed << setprecision(7);

    double S = 1. * x / a;
    if(a * b >= S * 2)
    {
        double e = S * 2 / b;
        cout << atan2(b, e) * 180. / M_PI << endl;
    }
    else // S = (b + e) * a / 2
    {
        double e = 2. * S / a - b;
        cout << atan2(b-e, a) * 180. / M_PI << endl;
    }
    

    return 0;
}
