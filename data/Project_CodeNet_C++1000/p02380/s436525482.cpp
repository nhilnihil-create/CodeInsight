#include <bits/stdc++.h>

using namespace std;

int main(){
    double a, b, C, S;
    cin >> a >> b >> C;
    C = C * M_PI / 180.0;
    S = (a * b * sin(C)) / 2;
    cout << fixed << setprecision(4) << S << endl
    << a+b+sqrt(a*a+b*b-2*a*b*cos(C)) << endl << 2*S/a << endl;
}