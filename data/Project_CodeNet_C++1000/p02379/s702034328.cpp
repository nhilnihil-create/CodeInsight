#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    double x1, y1, x2, y2;
    double base, height, hype;
    
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    
    base = abs(x1 - x2);
    height = abs(y1 - y2);
    
    hype = sqrt(pow(base, 2) + pow(height, 2));
    
    printf("%lf\n", hype);
    
    return 0;
}
