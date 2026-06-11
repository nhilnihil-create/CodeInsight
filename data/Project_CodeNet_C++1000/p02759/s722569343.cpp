#include <stdio.h>
int main(){
	 int a;
	  
	scanf("%d",&a);
	
	  if(a % 2 == 0){
			
		a /=2;  	
			printf("%d",a);   	
	  } 
	  else{
	  	
	  	a /=2;
	  		printf("%d",a+1);
	  }
	
	return 0;
}