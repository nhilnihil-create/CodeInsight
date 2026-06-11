#include <bits/stdc++.h>
using namespace std;

int main(){
    const double PI = 3.14159265358979323846;
    double A, B, H, M;
    cin >> A >> B >> H >> M;
    
    double theta_a, theta_b;
    theta_a = 2 * PI * (60 * H + M) / (60 * 12);
    theta_b = 2 * PI * M / 60;
    
    double ans;
    ans = sqrt(A*A + B*B - 2*A*B*cos(theta_a - theta_b));
    
    cout << scientific << setprecision(10) << ans << endl;
}
