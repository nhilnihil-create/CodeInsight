#include <cstdio>

using namespace std;

int main(void) {
    double a;
    
    scanf("%lf", &a);
    printf("%.6f %.6f\n", a * a * 3.141592653589, (2 * a) * 3.141592653589);
    
    return 0;
}