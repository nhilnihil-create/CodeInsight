#include <bits/stdc++.h>
#include <string>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    ll w, h, x, y;
    double ans;

    cin >> w >> h >> x >> y;

    ans = (double)(w * h) / 2;
    cout << fixed << setprecision(10) << ans;
    if ((double)x== (double)w/2.0 && (double)y== (double)h/2.0)
        cout << " 1" << endl;
    else
        cout << " 0" << endl;

    return 0;
}
