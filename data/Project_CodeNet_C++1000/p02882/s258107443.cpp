#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define rad2deg(a) ((a)/M_PI * 180.0)
#define deg2rad(a) ((a)/180.0 * M_PI)
const std::string yes = "Yes";
const std::string no  = "No";

int main(){
    double a,b,x;
    std::cin >> a >> b >> x;

    double ans;
    if(((a*a*a)/(2.0*(a*a*b-x)))>=a/b) ans = atan((a*a*a)/(2.0*(a*a*b-x)));
    else ans = atan(2.0*x/(a*b*b));
    std::cout << std::fixed << std::setprecision(10) << 90-rad2deg(ans) << "\n";
    return 0;
}
