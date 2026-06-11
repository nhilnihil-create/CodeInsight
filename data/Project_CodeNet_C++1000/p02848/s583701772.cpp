#include <stdio.h>

int main(){
   	int n;
   	char input[100000];
   	scanf("%d", &n);
   	scanf("%s", input);
   	
   	for(int i = 0; input[i] != '\0'; i++){
   		for(int j = 0; j < n; j++){
   			
		 	if(input[i] == 90){
			 	input[i] -= 26;
				 	
			 	input[i]++;
		    } 
			else {
		    	input[i]++;
			}
		}
		printf("%c", input[i]);	
	}
	return 0;
} 