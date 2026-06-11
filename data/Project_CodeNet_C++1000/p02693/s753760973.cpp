#include<stdio.h>

int main(){
     int K,A,B;
     int Count= 0;
     scanf("%d",&K);
     scanf("%d %d",&A,&B);
     for(int i=A;i<=B;i++){
         if(i%K==0){
             Count++;
         }
     }    
     
     if(Count > 0){
              printf("OK\n");
     } else {
              printf("NG\n");
     }





    return 0;
}