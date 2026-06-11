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
    vector<long> a(n);
    vector<long> ord(n, 0);
    for(long i = 0; i < n; i++){
        scanf("%ld", &a[i]);
        long k = a[i];
        while(k % 2 == 0){
            k /= 2;
            ord[i]++;
        }
        if(ord[i] != ord[0]){
            printf("%d", 0);
            return 0;
        }
    }
    
    long nLCM = 1;
    for(long i = 0; i < n; i++){
        nLCM = GetLCM(nLCM, a[i]);
        if(nLCM > 2 * m){
            printf("%d", 0);
            return 0;
        }
    }
    long HalfLCM = nLCM / 2;
    long nAns = (m / HalfLCM) - (m / nLCM);
    printf("%ld", nAns);
  
    return 0;
}
