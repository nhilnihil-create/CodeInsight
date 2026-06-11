#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int temp = 0;
    for(int i = 1; i <= 9; i++){
        if((double)N / i <= 9 && (double)N / i >= 1 && N % i == 0){
            temp = 1;
            break;
        }
    }
    if(temp == 1){
        puts("Yes");
    }else{
        puts("No");
    }
    return 0;
}