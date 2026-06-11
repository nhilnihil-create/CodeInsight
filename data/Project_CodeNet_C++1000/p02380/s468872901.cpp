#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    const double pi=3.1415926535897932384626433832795028841971693;
    double s1,s2,s3,a;
    cin >> s1 >> s2 >> a;
    cout << setprecision(20)<< fixed << (1/2.0)*(s1)*(s2)*(sin(a*pi/180)) << endl;
    s3=sqrt(pow(s1,2)+pow(s2,2)-2*s1*s2*cos(a*pi/180));
    cout << s1+s2+s3 << endl;
    cout << s2*sin(a*pi/180) << endl;
}
