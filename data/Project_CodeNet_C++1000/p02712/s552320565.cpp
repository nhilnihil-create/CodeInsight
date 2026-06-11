#include<stdio.h>

int main(){
	int batas;
	long long int jumlah=0;

	scanf("%d", &batas);
	    for(int i=1; i <= batas; i++ ){
        if(i % 3 == 0 && i % 5 == 0){
            i-i;
        }
        else if(i % 3 == 0){
            i-i;
        }
        else if (i % 5 == 0){
            i-i;
        }
        else {
			jumlah+=i;
        }
    }
    printf("%lld", jumlah);
 	
	return 0;
}