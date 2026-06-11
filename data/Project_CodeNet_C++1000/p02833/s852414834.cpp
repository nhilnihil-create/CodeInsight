#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long n;
    scanf("%ld", &n);
    if(n % 2 == 1 || n == 0){
        printf("%d", 0);
    } else {
        long nCount = 0;
        nCount += n / 10;
        n /= 10;
        while(n >= 5){
            nCount += n / 5;
            n /= 5;
        }
        printf("%ld",nCount);
    }
    
    
    return 0;
}
