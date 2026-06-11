#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265358979323846264338327950L

int main(void){
    double a,b,h,m;
    cin >> a >> b >> h >> m;
    
    double s_dig = (double)(h*60+m)*(pi/360);
    double l_dig = (double)(m)*(pi/30);
    
    double rad = abs(s_dig - l_dig);
    
    double ct =  (double)(a*a + b*b) - (double)(2*a*b) * (double)cos(rad);
    
    double ans =  (double)sqrt(ct);
    
    cout << fixed << setprecision(20) << ans;
    
    return 0;
}
