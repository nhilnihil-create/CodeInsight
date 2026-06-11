#include <stdio.h>


int main(){
    long a;
    scanf("%ld", &a);

    long sum = 0;
    for (long i=1; i<=a; i++){
        if (i%15 == 0 || i%3 == 0 || i%5 == 0){
            continue;
        }
        else{
            sum += i;
        }
    }
    
    printf("%ld\n", sum);
    return 0;
}