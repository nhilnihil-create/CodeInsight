#include <iostream>
using namespace std;

int main(void){

    int a = 16;
    int b = 18;

    int d;
    int r;
    double f;
    
    std::cin >> a >> b;
    
    d = a / b;
    r = a % b;
    f = (double)a / (double)b;
    
    printf("%d %d %.5lf", d, r, f);

    return 0;
}