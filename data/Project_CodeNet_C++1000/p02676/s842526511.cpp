#include <stdio.h>
#include <string.h>

int main(){  
	int angka; 
    char x[255];
    scanf("%d", &angka);
    scanf("%s",x);
    int a= strlen(x);	
	if(a > angka){
        for(int i=0;i<angka;i++){
            printf("%c",x[i]);
        }
        printf("...");
    }
    else if(a == angka|| a < angka){
        printf("%s",x);
    }
    return 0;
}

 