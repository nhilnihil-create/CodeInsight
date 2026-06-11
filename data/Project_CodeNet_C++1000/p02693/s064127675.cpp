#include<stdio.h>
int main (){
	int aa;
	int ba;
	int ka;
	int hasila= 0;
	
	scanf("%d", &ka);
	scanf("%d %d", &aa ,&ba);
	
	for(int i=aa;i<=ba;i++){
		if(i%ka==0){
			hasila++;
		}
	}
		if(hasila !=0){
		printf("OK");
		}else{
			printf("NG");	
		}
	return 0;
}