#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int iAns;
    if(n % 27 == 13 || n % 27 == 26){
        printf(":(");
    } else if (n % 27 < 13){
        iAns = (n / 27) * 25 + (n % 27);
        printf("%d", iAns);
    } else {
        iAns = (n / 27) * 25 + (n % 27) - 1;
        printf("%d", iAns);
    }
    
    return 0;
}
