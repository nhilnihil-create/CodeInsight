#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int m1,m2,d1,d2;
    scanf("%d %d %d %d", &m1, &d1, &m2, &d2);
    if(m1 == m2){
        printf("0");
    } else {
        printf("1");
    }
    return 0;
}
