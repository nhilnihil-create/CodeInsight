#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    
    double r;
    cin >> r;
    
    printf("%.5f %.5f",M_PI * r * r,2 * M_PI * r);
    
    return 0;
}