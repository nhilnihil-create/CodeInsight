#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main(){
        double a,b,theta;
        cin >> a >> b >> theta;
        cout << setprecision(20);
        cout << (a*b*sin(( theta/360) * 2*M_PI))/2 << endl;
        cout << a+b+pow(a*a + b*b - 2*a*b*cos( (theta/360) * (2*M_PI)),0.5) << endl;
        cout << ((a*b*sin(( theta/360) * 2*M_PI)))/a << endl;

return 0;
}