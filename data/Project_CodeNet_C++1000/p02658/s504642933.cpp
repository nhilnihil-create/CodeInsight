#include <stdio.h>

int main(){
    long long jumlah;
    scanf("%lld", &jumlah);

    long long var[jumlah+1];
    long long result = 1;
    int flag = 1;
    int print_hasil;

    for(int i = 0; i<jumlah; i++){
        scanf("%lld", &var[i] );
        if ( var[i] == 0 ) {
            printf("0\n");
            flag = 0;
            break;
        }
    }

    if(flag){
        for(int i = 0 ; i < jumlah ; i++){
            if(var[i] > 1000000000000000000/result) {
                flag = 0;
                break;
            }
            result *= var[i]; 
            if ( i >= jumlah - 1 ){
          		print_hasil = 1;
        }
    }

    if ( print_hasil ) {
        flag ? printf("%lld\n", result) : printf("-1\n");
    }

    return 0;
    }
}