#include <stdio.h>
#include <string.h>
int main (){
	int k;
	int i;
    char s[101];
    	scanf("%d",&k);
    		scanf("%s",&s);
    int len = strlen(s);
    if (len<=k){	
	printf("%s",s);
	}
    
    else {
    	for (int i=0 ; i<k ;i++){
    		printf("%c",s[i]);
		}
		printf("...\n");
}

	
	return 0;
}