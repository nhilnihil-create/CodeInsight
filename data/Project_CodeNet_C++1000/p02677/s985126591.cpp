#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main(void)
{
    ld a,b,h,m;
    ld x;
    cin >> a >> b >> h >> m;
    ld theta = abs(6*m - (30*h + m/60*30));
    if(theta > 180)
    {
        theta = 360 - theta;
    }
    //cout << theta << endl;
    theta = theta * M_PI / 180;
    ld abcos = a*b*cos(theta);
    x = sqrt( abs(b*b - 2*abcos + a*a));

    cout << fixed << setprecision(10) << x << endl;
    
    return 0;
}
