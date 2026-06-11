#include <stdio.h>

int main(){
	
	int n;
	scanf("%d", &n);
	
	int divide = n/2;
	// printf("divide: %d\n", divide);
	char str[110];
	scanf("%s", str);
	
	if(n%2 != 0){
		printf("No");
		return 0;
	}

	for(int i = 0 ; str[i] != '\0' ; i++){
		if(i == divide){
			break;
		}
		if(str[i] != str[i+divide]){
			//printf("Indexing: %d\n", i+divide);
			//printf("Where: %d\n", i);
			printf("No\n");
			return 0;
		}
	}
	printf("Yes");
	
	return 0;
}