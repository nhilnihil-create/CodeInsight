#include <iostream>
#include <cstdio>
using namespace std;

#define N 1000000007

long pow(long m ,long n){
    
    if (n==0) return 1;
    
    if (n%2 == 0) return pow((m*m) % N, n/2) % N;
    else        return (pow((m*m) % N, n/2) * m) % N;
}


int main(){
    
    int m , n;
    long ans = 0;
    
    cin >> m >> n;
    
    ans = pow(m, n);
    
    printf("%ld\n", ans);
    
    return 0;
}