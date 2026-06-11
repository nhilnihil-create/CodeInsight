#include <cstdio>

using namespace std;

int main(void) {
    int a, b;
    
    scanf("%d%d", &a, &b);
    printf("%d %d %.5f", a / b, a % b, (double)a / (double)b);
    
    return 0;
}