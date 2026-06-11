#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
    double r,h =3.141592653589 ;
    cin >> r;
    double i = r*r*h;
    double j = (r+r)*h;
    
    cout << fixed << setprecision(5);
    cout << i << " " << j << endl;
}    
