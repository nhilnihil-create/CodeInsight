#include <stdio.h>
int main(){
	int n;
	char str[n+2];
	
	scanf("%d", &n);
	scanf("%s", str);
	if(n % 2 != 0){
		printf("No");
		return 0;
	}
	for(int i =0; i<n/2; i++){
		if(str[i]!=str[(n/2)+i]){
			printf("No");
			return 0;
		}
	}
	printf("Yes");
 
	
	return 0;
}