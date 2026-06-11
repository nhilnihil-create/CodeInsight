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
            for ( kari1 = 0; kari1 < tate; kari1++ ){
                for ( kari2 = 0; kari2 < yoko; kari2++ ){
                printf("#");
				}
			printf("\n");
			}
		}
		printf("\n");
	}
    return(0);
}