#include <stdio.h>
int main(){
	int num;
	scanf("%d", &num);
	char str[num+2];
	scanf("%s", &str);
	if(num % 2 != 0){
		printf("No\n");
		return 0;
	}
	for(int i =0; i<num/2; i++){
		if(str[i]!=str[(num/2)+i]){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");

	
	return 0;
}
