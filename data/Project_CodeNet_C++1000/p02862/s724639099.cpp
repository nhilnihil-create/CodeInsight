#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
const long nPrime = 1000000007;

long Factorial(const long &n){
    //nPrime = 1000000007
    long nReturn = 1;
    for(long i = 2; i <= n; i++){
        nReturn *= i;
        nReturn %= nPrime;
    }
    return nReturn;
}

long Inverse(const long &n){
    //nPrime = 1000000007
    if (n % nPrime == 0){
        return 0;
    }
    long a = n, b = nPrime, u = 1, v = 0;
    while (b > 0) {
        long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= nPrime;
    if (u < 0){
        u += nPrime;
    }
    return u;    
}

int main(){
    long x,y;
    scanf("%ld %ld", &x, &y);
    if((x + y) % 3 != 0 || 2 * x < y || 2 * y < x){
        printf("0");
        return 0;
    }
    long a,b;
    a = (2 * x - y) / 3;
    b = (2 * y - x) / 3;
    if(a * b == 0){
        printf("1");
    } else {
        long nAns = Factorial(a+b) * Inverse(Factorial(a));
        nAns %= nPrime;
        nAns *= Inverse(Factorial(b));
        nAns %= nPrime;
        printf("%ld", nAns);
    }
    
    return 0;
}
