#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main(void){
    double r;
    double squ, cir;
    cin >> r;
    squ = r*r*3.141592653589;
    cir = 2*r*3.141592653589;
    cout << fixed << setprecision(12) << squ << " " << cir << endl;
    return 0;
}