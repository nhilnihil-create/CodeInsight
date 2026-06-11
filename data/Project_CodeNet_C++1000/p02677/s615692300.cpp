#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cout << fixed << setprecision(20) << flush;

    int a, b, h, m;
    cin >> a >> b >> h >> m;

    double a_ang = 30.0*h + 0.5*m;
    double b_ang = 6.0*m;
    double co = cos((a_ang-b_ang) * 2.0*M_PI/360.0);
    double c = sqrt(a*a+b*b-2*a*b*co);
    cout << c << endl;

    return 0;
}