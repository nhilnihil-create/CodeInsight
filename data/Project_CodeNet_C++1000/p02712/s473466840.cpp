#include<stdio.h>
int main(){
    long long int input;
    long long int sum = 0;
    scanf("%lld", &input);
    for(int i = 1; i <= input; i++){
        if(i % 3 != 0 && i % 5 != 0)//jika kedua nya tidak habis dibagi 5 dan 3
        {
            sum = sum + i;//sum dijumlah
        }
    }
    printf("%lld\n", sum);
    return 0;
}