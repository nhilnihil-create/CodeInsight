#include <stdio.h>

int main(){

    long long int ang;
    long long int ttl = 1;
    long long int N[100005];
    bool lanjut = true;
    bool printtotal = true;
    scanf("%lld", &ang);
    
    for (long long int i = 1; i <= ang; i++){
        scanf("%lld", &N[i]);
        if(N[i]==0){
            printf("0\n");
            lanjut = false;
            break;
        }
    }
    
      if(lanjut){
          for(int i = 1; i<=ang;i++){
                if(1000000000000000000/ttl >= N[i]){
                  ttl *= N[i];
            }
            else{
                printf("-1\n");
                printtotal = false;
                break;
            }    
        }    
        if(printtotal){
            printf("%lld\n",ttl);
        }
    }
    return 0;
}