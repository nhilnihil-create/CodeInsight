#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	char string[n];
	scanf("%s",string);
	
	int flag = 1;
	
	if (n%2 == 1){
		printf("No");
		return 0;
	} else{
	for (int i=0 ; i < n/2 ; i++){
		if (string[i] == string[i+n/2]){
	
		}
		else {
			flag = 0;
		}
	}
}
	(flag==1)?printf("Yes"):printf("No");	
	return 0;
}