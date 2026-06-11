#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long a, b, k;
    scanf("%ld %ld %ld", &a, &b, &k);
    if(a + b <= k){
        printf("%ld %ld", 0, 0);
    } else if (a <= k){
        printf("%ld %ld", 0, a+b-k);
    } else{
        printf("%ld %ld", a-k, b);
    }
    
    return 0;
}
