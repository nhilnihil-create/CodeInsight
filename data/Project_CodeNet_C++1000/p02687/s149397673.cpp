#include <stdio.h>
int main (){
	char contest1[10] ; 
	scanf("%s",contest1);	
	
	if (contest1[1]=='B'){
		printf("ARC");
	}else{
		printf("ABC");
	}
	
	return 0;
}