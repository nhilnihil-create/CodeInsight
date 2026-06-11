#include <cstdio>

using namespace std;

int main(){
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    printf("%d %d %lf", a / b, a % b, static_cast<double>(a) / b);
    
    return 0;
}