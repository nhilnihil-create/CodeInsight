#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int fib(int n){
  
    if(n == 0 || n == 1){
        return 1;
    }
    
    int ans = 0;
    int fib_1, fib_2;
    fib_1 = 1;
    fib_2 = 1;
    
    for(int i = 2; i <= n; i++){
        ans = fib_1 + fib_2;
        fib_2 = fib_1;
        fib_1 = ans;
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
    //Input
    int n;
    scanf("%d", &n);
    
    printf("%d\n", fib(n));
           
    return 0;
}