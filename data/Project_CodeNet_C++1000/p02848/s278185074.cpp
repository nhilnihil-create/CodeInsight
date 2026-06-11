#include <stdio.h>

int main(){
	int n=0;
	char str[10000];
	scanf("%d", &n);
	scanf("%s", &str);
	
	for(int i=0;str[i]!='\0';i++){
			str[i]+=n;
		if(str[i]>'Z'){
			str[i]-=26;
		}
		printf("%c", str[i]);
	}
	
	
	return 0;
}