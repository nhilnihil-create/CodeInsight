#include <iostream>
#include <cstdio>
                
int main() {    
    int x, y, d, r = 0;
    double f = 0.0;
                
    std::cin >> x >> y;
    d = x / y;  
    r = x % y;  
    f = (double)x / (double) y;
                
    printf("%d %d %f\n", d, r, f);
    return 0;   
}