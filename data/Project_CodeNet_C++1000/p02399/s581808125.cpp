#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int a, b, r1,rem;
    double r2;
    cin >> a >> b;
    r1 = a / b;
    rem = a % b;
    r2 = 1.0 * a / b;
    cout << r1 << " " << rem << " ";
    printf("%.8lf\n", r2);
    return 0;
    
}