#include <bits/stdc++.h>
using namespace std;
int main(){
    double a, b, x;
    cin>>a>>b>>x;
    double r;
    if(x <= a*a*b/2) r = atan2(b*b, 2*(x/a));
    else r = atan2(2*(a*b-(x/a)), a*a);
    double ans = r/(2*acos(-1)) * 360;
    cout << fixed << setprecision(12) << ans << endl;
}
