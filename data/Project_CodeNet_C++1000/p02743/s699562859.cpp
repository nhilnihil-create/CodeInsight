#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long a,b,c;
    scanf("%ld %ld %ld", &a, &b, &c);
    if(a + b > c){
        printf("No");
    } else if ((a + b - c) * (a + b - c) > 4 * a * b){
        printf("Yes");
    } else {
        printf("No");
    }
    
    return 0;
}
