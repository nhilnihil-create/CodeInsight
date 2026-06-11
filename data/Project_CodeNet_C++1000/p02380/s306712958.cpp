#include<iostream>
#include<math.h>
#include<iomanip>
#define Pi 3.14159265358979
using namespace std;
int main(){
    double a,b,c,alpha;
    cin >> a >> b >> alpha;
    double val=Pi*alpha/180;
    c = sqrt(a*a + b*b -2*a *b *cos(val));  
    double s=  a* b* sin(val)/2,h=2*s/a,l=a+b+c;
    cout << fixed;
    cout << setprecision(8) << s << endl << l << endl << h << endl;

    return 0;
}