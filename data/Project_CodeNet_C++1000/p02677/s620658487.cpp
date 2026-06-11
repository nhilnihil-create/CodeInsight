#include <bits/stdc++.h>
using namespace std;
int main(){
    long double ans, rad, pie=3.14159265359, h, m, a, b;
    cin >> a >> b >> h >> m;
    rad=abs((30*h+0.5*m)-6*m);
    rad/=180;
    ans=(a*a)+(b*b)-(2*a*b*(cos(rad*pie)));
    ans=sqrt(ans);
    cout << fixed << setprecision(15) << ans <<endl;
    return 0;
}