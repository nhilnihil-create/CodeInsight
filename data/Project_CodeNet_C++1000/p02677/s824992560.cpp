#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    int A, B, H, M;
    cin >> A >> B >> H >> M;
    ld pi = 3.14159265358979323846;
    ld thetaA = (60*H+M)*(2*pi)/(12*60);
    ld thetaB = (M*(2*pi))/60;
    ld theta = abs(thetaA-thetaB);
    if (theta > pi) {
        theta = 2*pi - theta;
    }
    ld ans = sqrt(pow(A*sin(theta),2)+pow(B-A*cos(theta),2));
    cout << fixed << setprecision(12);
    cout << ans << endl;
}