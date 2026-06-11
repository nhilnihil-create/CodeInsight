#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    double r;
    double pi = 3.14159265359;
    cin >> r;
    
    printf("%.6lf %.6lf", r * r * pi, 2 * r * pi);
    cout << endl;
    return 0;
}

