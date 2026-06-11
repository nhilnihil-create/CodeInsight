#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int a, b, quot, remain;
    double floatNum;
    
    cin >> a >> b;
    quot = a / b;
    remain = a % b;
    floatNum = (double)a / (double)b;
    
    printf("%d %d %f\n", quot, remain, floatNum);
    
    return 0;
}