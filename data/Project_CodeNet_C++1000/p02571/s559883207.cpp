#include <stdio.h>
#include <string.h>
 
int main() {
	
	char S[1001] = {'\0'};
  	char T[1001] = {'\0'};
	 
	int count = 0, min = 1000;
	 
//	gets(S);
//	gets(T);
	scanf("%s", S);
	getchar();
	scanf("%s", T);
	getchar();
	int len1 = strlen(S);
	int len2 = strlen(T);
 
	for(int i=0; i + len2 <= len1;i++){
	    count = 0;
	    for(int j=0; j<len2; j++){
	      	if(S[i+j] != T[j]){
	        	count++;
	      	}
	    }
	    if(min > count) min = count;
  	}
  	printf("%d\n",min);
 
 
  return 0;
}