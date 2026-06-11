#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    int A,B,H,M;
    cin >> A >> B >> H >> M;
    double ans;
    double pi = 3.141592653589793;
    double A2 = pow(A, 2);
    double B2 = pow(B, 2);
    double H2 = H+M/60.0;

    ans = pow(A2+B2-2*A*B*cos((5*H2-M)*pi/30), 0.5);
    cout << fixed << setprecision(20) << ans << endl;
}