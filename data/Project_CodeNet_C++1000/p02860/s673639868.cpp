#include <stdio.h>
#include <string.h>
int main(){
	int n;
	char s[102]={};
	int ctr=0;
	scanf("%d", &n);
	scanf("%s", &s);
	if(n%2!=0){
		printf("No");
		return 0;
	}
	int half=n/2;
	for(int i=0;i<half;i++){
		if (s[i]==s[i+half]){
			ctr++;
		}
	}
	if(ctr==half){
		printf("Yes");
	}else{
		printf("No");
	}
	
	return 0;
}