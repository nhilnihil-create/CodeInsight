#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cout << fixed << setprecision(10) << flush;

    double a, b, x;
    cin >> a >> b >> x;
    x /= (a*a);
    if(x > b/2.0) cout << atan(2.0*(b-x)/a)*180/M_PI << endl;
    else cout << atan(b*b/(2.0*a*x))*180/M_PI << endl;

    return 0;
}