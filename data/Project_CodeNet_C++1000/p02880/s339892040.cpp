#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
		int stop=1;
	
	if(n>=1&&n<=81){
	for(int i=1;i<=9;i++){
	
		for(int j=1;j<=9;j++){
			int temp = i*j;
			if(n==temp){
				printf("Yes");
				stop--;
				break;
		}
	}
	if(stop==0){
		break;
			}
	}	
		}
			else{
				printf("No");
				stop--;
				}
					if(stop>0){
					printf("No");
			
		}
	return 0;
}