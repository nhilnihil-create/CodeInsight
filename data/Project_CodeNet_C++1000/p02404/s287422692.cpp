#include <stdio.h>
 
int main(void){
	int yoko,tate;
	int kari1,kari2;
	while(1){
		scanf("%d %d",&tate,&yoko);
		if(yoko == 0 && tate == 0){
			break;
		}else{
			kari1 = 0,kari2 = 0;
			 for ( kari2 = 0; kari2 < yoko; kari2++ ){
                printf("#");
				}
			printf("\n");
            for ( kari1 = 0; kari1 < tate-2; kari1++ ){
				printf("#");
                for ( kari2 = 0; kari2 < yoko-2; kari2++ ){
                printf(".");
				}
				printf("#");
				printf("\n");
			}
		}
		 for ( kari2 = 0; kari2 < yoko; kari2++ ){
                printf("#");
				}
		printf("\n\n");
	}
    return(0);
}