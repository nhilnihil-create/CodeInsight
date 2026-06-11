#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int s,w;
    scanf("%d %d", &s, &w);
    if(s > w){
        printf("safe");
    } else {
        printf("unsafe");
    }
    
    return 0;
}
