#include <stdio.h>
 
int main(){
    int N;
    scanf("%d", &N);
 
    for(int i=1; i<=9; i++){
        if( N/i < 10 && N%i == 0){
        puts("Yes");
        return 0;
        }
    }
    puts("No");
    return 0;
}