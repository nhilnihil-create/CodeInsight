#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

long GetLCM(const long &a, const long &b){
    long x = max(a,b);
    long y = min(a,b);
    while(x % y != 0){
        long t = x % y;
        x = y;
        y = t;
    }
    return a * b / y;  
}

int main(){
    long n,m;
    scanf("%ld %ld", &n, &m);
    printf("%ld", GetLCM(n,m));
    return 0;
}
