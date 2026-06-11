#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long n;
    scanf("%ld", &n);
    long ia[60] = {0};
    for(long i = 0; i < n; i++){
        long a;
        scanf("%ld", &a);
        for (int j = 0; j < 60; j++){
            ia[59 - j] += a % 2;
            a /= 2;
        }
    }
    long iTwoPow[60];
    iTwoPow[0] = 1;
    for(int i = 1; i < 60; i++){
        iTwoPow[i] = 2 * iTwoPow[i - 1];
        iTwoPow[i] %= 1000000007;
    }
    long nAns = 0;
    for(int i = 0; i < 60; i++){
        long iA = (ia[59 - i]) * (n - ia[59 - i]);
        iA %= 1000000007;
        iA *= iTwoPow[i];
        iA %= 1000000007;
        nAns += iA;
        nAns %= 1000000007;
    }
    
    printf("%ld",nAns);
    return 0;
}
