#include <stdio.h>

int main(){

    long long int brpKali;
    int count=0;
    long long int hasil=0;
    int i=1;
    int j=0;
    long long int arrTampungan[1000000];
    scanf("%lld", &brpKali);
    while(i<=brpKali){
        if(i%3==0 && i%5!=0){
            //printf("Fizz");
        }
        else if(i%5==0 && i%3!=0){
            //printf("Buzz");
        }
        else if(i%3==0 && i%5==0){
            //printf("FizzBuzz");
        }
        else{
           // printf("%d", i);
            arrTampungan[j]=i;
           // printf("\n ini array tampungan ke-%d :%d\n",j , arrTampungan[j]);
            count++;
            j++;
        }
        i++;

    }
 for(int k=0;k<count;k++){
    hasil+=arrTampungan[k];
 }
printf("%lld\n", hasil);
 
 
    return 0;
}