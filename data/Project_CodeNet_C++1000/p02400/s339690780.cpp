#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    double PI = 3.141592653589;
    double r;
    cin >> r;
    
    printf("%5f %5f\n", r * r * PI, r *2 * PI);
    
    return 0;
}