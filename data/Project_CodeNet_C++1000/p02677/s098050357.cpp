#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,h,m;
    cin >> a >> b >> h >> m;
    const double pi = acos(-1.0);
    double alpha = (h*60+m)*2*pi/720;
    double beta = m*pi*2/60;
    double gamma = alpha - beta;
    double ans = sqrt(a*a + b*b - 2*a*b*cos(gamma));
    cout << fixed << setprecision(10) << ans << endl;
}