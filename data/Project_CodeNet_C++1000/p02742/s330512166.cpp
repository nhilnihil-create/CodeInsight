#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long h,w;
    scanf("%ld %ld", &h, &w);
    if(h == 1 || w == 1 ){
        printf("%d", 1);
    } else {
        printf("%ld", (h * w + 1)/2);
    }
    return 0;
}
