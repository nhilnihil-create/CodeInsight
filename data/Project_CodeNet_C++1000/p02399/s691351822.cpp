#include <iostream>
#include <iomanip>
using namespace std;

int main(void){
    
    unsigned int a = 0;
    unsigned int b = 0;

    cin >>  a >> b;
    
    unsigned int d = a / b;
    unsigned int r = a % b;
    double f = (double)a / b;
    
    cout << d << ' ' << r  << ' ' << fixed << setprecision(6) << f << endl;
    
    return 0;
}