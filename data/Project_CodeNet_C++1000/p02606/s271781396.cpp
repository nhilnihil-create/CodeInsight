#include <string.h>
#include <stdio.h>
int main (){
	int modulo,range1, range2,a=0 ;
	scanf("%d %d %d",&range1, &range2,&modulo);
	for (int i=range1;i<=range2;i++){
		if (i % modulo == 0 ){
		    a++ ;
		}
	}
	printf("%d",a);
}