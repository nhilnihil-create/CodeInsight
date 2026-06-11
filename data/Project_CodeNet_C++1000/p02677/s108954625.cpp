#include <bits/stdc++.h>
using namespace std;

int main(){

    int A,B,H,M;
    cin >> A >> B >> H >> M;

    long double M_rad = (M_PI / 30) * M;
    long double H_rad = (M_PI / 6) * H + M_rad / 12;
    long double theta = abs(M_rad - H_rad);

    long double res = (A*A) + (B*B) - (2*A*B*cos(theta));
    res = sqrt(res);

    cout << fixed << setprecision(20) << res;
    return 0;
}