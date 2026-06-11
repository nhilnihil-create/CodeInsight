#include <stdio.h>

int main(){
   	int n;
   	char s[10000001];
   	scanf("%d", &n);
   	scanf("%s", s);
   	
   	for(int i = 0; s[i] != '\0'; i++){
   		for(int j = 0; j < n; j++){
		 	if(s[i] == 90){
			 	s[i] -= 26;	
			 	s[i]++;
		    } 
            else{
		    	s[i]++;
			}
		}
		printf("%c", s[i]);	
	}
	
	return 0;
} 