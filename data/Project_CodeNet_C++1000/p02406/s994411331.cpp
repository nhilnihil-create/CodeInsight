#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    int N, x;
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        x = i;
        if(i % 3 == 0)
            printf(" %d", i);
        else{
            while(x){
                if(x % 10 == 3){
                    printf(" %d", i);
                    break;
                }
                x /= 10;
            }
        }
    }
    printf("\n");
    return 0;
}