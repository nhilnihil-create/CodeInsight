#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long t1,t2,a1,a2,b1,b2;
    scanf("%ld %ld", &t1, &t2);
    scanf("%ld %ld", &a1, &a2);
    scanf("%ld %ld", &b1, &b2);
    if(t1 * (a1 - b1) + t2 * (a2 - b2) == 0){
        printf("infinity");
        return 0;
    }
    if(t1 * (a1 - b1) + t2 * (a2 - b2) < 0){
        swap(a1, b1);
        swap(a2, b2);
    }
    
    if(a1 - b1 > 0){
        printf("0");
    }
    else {
        long iDist1 = t1 * (b1 - a1);
        long iDist2 = t1 * (a1 - b1) + t2 * (a2 - b2);
        if(iDist1 % iDist2 == 0){
            printf("%ld", 2*(iDist1 / iDist2));
        }
        else{
            printf("%ld", 2*(iDist1 / iDist2) + 1);
        }
    }
    return 0;
}
