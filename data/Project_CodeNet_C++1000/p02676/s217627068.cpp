#include<stdio.h>
#include<string.h>
int main(){
	
	int n;
	char s[1000];
	scanf("%d",&n);
	scanf("%s",s);
	if(n>=strlen(s)){
		printf("%s\n",s);
	}else{
		for(int i=0; i<=n; i++){
			if(i==n){
				puts("...");
			}else{
				printf("%c",s[i]);	
			}
		}
	}
	
	return 0;
}