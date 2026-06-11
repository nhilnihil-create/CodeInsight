#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long n;
    scanf("%ld", &n);
    vector<long> viMax(n);
    vector<long> viMin(n);
    for(long i = 0; i < n; i++){
        scanf("%ld %ld", &viMin[i], &viMax[i]);
    }
    sort(viMax.begin(), viMax.end());
    sort(viMin.begin(), viMin.end());
  
    if(n % 2 == 1){
        long i = viMax[n / 2];
        long j = viMin[n / 2];
        printf("%ld", i - j + 1);
    } else {
        long i = viMax[n / 2] + viMax[n / 2 - 1]; //2倍
        long j = viMin[n / 2] + viMin[n / 2 - 1];
        printf("%ld", i - j + 1);
    }
    return 0;
}