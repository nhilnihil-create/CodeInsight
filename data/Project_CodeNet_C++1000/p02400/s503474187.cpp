#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

double r;

int main(){
    cin >> r;
    printf("%.7f %.7f\n", pow(r, 2)*M_PI, 2*r*M_PI);
    
    return 0;
}
