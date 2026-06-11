#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    char str[n];
    scanf("%s", str);
    int nCount = 0;
    for(int i = 0; i < n - 2; i++){
        if(str[i] =='A' && str[i+1] == 'B' && str[i+2] == 'C'){
            nCount++;
        }
    }
    
    printf("%d", nCount);
    return 0;
}
