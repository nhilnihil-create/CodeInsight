#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int X;
    scanf("%d", &X);
    if(X >= 2000){
        printf("1");
    } else {
        bool bCanPay = false;
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 20; j++){
                for(int k = 0; k < 20; k++){
                    for(int l = 0; l < 20; l++){
                        for(int m = 0; m < 20; m++){
                            for(int n = 0; n < 20; n++){
                                if(100 * i + 101 * j + 102 * k + 103 * l + 104 * m + 105 * n == X){
                                    bCanPay = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(bCanPay){
            printf("1");
        } else {
            printf("0");
        }
    }
  
    
    return 0;
}
