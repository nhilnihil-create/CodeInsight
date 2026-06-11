#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

    int a    = 0;
    int b    = 0;
    int d    = 0;
    int r    = 0;
    double f = 0.0;

    cin >> a;
    cin >> b;

    d = a / b;
    r = a % b;
    f = (double)a / (double)b;
 
//    cout << d << " " << r << " " << f << std::endl;
    printf("%d %d %f\n",d,r,f);
}