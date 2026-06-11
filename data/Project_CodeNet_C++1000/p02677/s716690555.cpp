#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B,H,M;
    long double ans;
    cin >> A >> B >> H >> M;
    long double A_deg,B_deg;
    A_deg = 30*H+(0.5*M);
    B_deg = 6*M;
    long double deg = abs((A_deg - B_deg));
    long double cdeg = abs(deg*M_PI/180.0);
    ans = sqrtl((long double)(A*A+B*B)-(long double)(2*A*B*(cosl(cdeg))));
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}