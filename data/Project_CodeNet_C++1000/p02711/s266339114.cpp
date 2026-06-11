#include<stdio.h>
#include<string.h>
int main(){
	
	char s[100];
	scanf("%s",s);
	int count=0;
	for(int i=0; i<strlen(s); i++){
		if(s[i]=='7'){
			count++;
		}else {
			continue;
		}
	}
	if(count>=1){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}