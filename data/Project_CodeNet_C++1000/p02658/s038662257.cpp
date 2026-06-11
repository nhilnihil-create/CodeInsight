#include <stdio.h>

int main(){

    long long int testcase;
    long long int total = 1;
    long long int A[100005]; //A untuk angka
    bool lanjut = true;
    bool printtotal = true;
    scanf("%lld", &testcase);
   
    
    for (long long int i = 1; i <= testcase; i++){ //kalau ada 0 auto
        scanf("%lld", &A[i]);
        if(A[i]==0){
            printf("0\n");
            lanjut = false;
            break;
        }
    }
    
      if(lanjut){
          for(int i = 1; i<=testcase;i++){
              if(1000000000000000000/total >= A[i]){
                  total *= A[i];
            }
            else{
                printf("-1\n"); //kelebihan dari 10^18
                printtotal = false;
                break;
            }    
        }    
        if(printtotal){   //kalau tidak print
            printf("%lld\n",total);
        }
    }
    return 0;
}