#include <stdio.h>

int main(){
	
	int N, total = 0;
	char str[110];
	
	scanf("%d", &N);
	scanf("%s", &str);
	
	for (int i = 0; i<N/2; i++){
		if(str[i] == str[i + N/2]){
			total++;
		}
	}if (N%2 != 0){
		printf("No\n");
		return 0;
	}
	
	total == N/2 ? printf("Yes\n") : printf("No\n");
	
	return 0;
}