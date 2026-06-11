#include <bits/stdc++.h>          
using namespace std;               
typedef long double ld;

int main() {
    int A, B, H, M;
    cin >> A >> B >> H >> M;
    ld pi = 3.1415926535897932384626433;
    ld ra = 2*pi/43200;
    ld rb = 2*pi/3600;
    ld ta = 3600*H + 60*M;
    ld tb = 60*M;
    ld theta = abs(ra*ta-rb*tb);
    if (theta>=2/pi) {
        theta = 2*pi-theta;
    }
    ld l = sqrt(A*A+B*B-2*A*B*cos(theta));
    cout << fixed << setprecision(10) << l << endl;
}