#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int nNum = 1;
    for(int i =0; i < n; i++){
        int a;
        scanf("%d", &a);
        if(a == nNum){
            nNum++;
        }
    }
    if(nNum >= 2){  
        printf("%d", n - nNum + 1);
    } else {
        printf("%d", -1);
    }
    return 0;
}
