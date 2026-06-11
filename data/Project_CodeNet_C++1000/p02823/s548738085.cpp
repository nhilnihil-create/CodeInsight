#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long n,a,b;
    scanf("%ld %ld %ld", &n, &a, &b);
    if(a > b){
        swap(a,b);
    }
    if( ( a + b ) % 2 == 0){
        printf("%ld", (b - a) / 2);
    } else {
        if(a + b >= n + 1){
            printf("%ld", n-b+1+(b-a-1)/2);
        } else {
            printf("%ld", a+(b-a-1)/2);
        }
    }
    
    return 0;
}
