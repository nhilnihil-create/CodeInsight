#include <bits/stdc++.h>
using namespace std;
int main(){
    double a, b; cin >> a >> b;
    double x; cin >> x; x /= (a*a);
    if(x<=(b/2)){
        double y = 2*a*x / b;
        double res = acos(y/(sqrt(b*b+y*y)));
        res = res*180/M_PI;
        cout << fixed << setprecision(15) << res << endl;
    }
    else{
        double y = 2*x - b;
        double res = acos(a/sqrt(a*a+(b-y)*(b-y)));
        res = res*180/M_PI;
        cout << fixed << setprecision(15) << res << endl;
    }
    return 0;
}