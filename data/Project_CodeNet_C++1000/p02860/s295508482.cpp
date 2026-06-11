#include <stdio.h>

int main () {
	int N;
	char str[100];
	scanf("%d", &N);
	scanf("%s", str);
	
	if(N%2==1) {
		printf("No");
		return 0;
	}
	
	for(int i=0;i<N/2;i++){
		if(str[i]==str[i+N/2]){
		continue;
		} else {
			printf("No");
			return 0;
		}
		
	}	
	printf("Yes");

	return 0;
}