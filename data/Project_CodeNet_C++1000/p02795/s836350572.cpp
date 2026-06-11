#include<stdio.h>
int main (){
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	int jwbn;
	if (z/x >z/y){
		
		if(z%y == 0){
			jwbn = z/y;
			
		}else {
			jwbn = z/y+1;
			
		}
	}else {
		if(z%x== 0){
			jwbn = z/x;
		}else{
			jwbn= z/x+1;
		}
	}
	printf("%d\n",jwbn);
	return 0;
	
	
	
	
}