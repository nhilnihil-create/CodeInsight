#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;

int main(){
    double a,b,c;
    cin >> a >> b >> c;
    cout << fixed << 0.5*a*b*sinf(c*M_PI/180) << endl;
    cout << fixed << a + b + sqrt(pow(a, 2) + pow(b, 2) - 2*a*b*cosf(c*M_PI/180)) << endl;
    cout << fixed << b*sin(c*M_PI/180) << endl;
    return 0;
}
