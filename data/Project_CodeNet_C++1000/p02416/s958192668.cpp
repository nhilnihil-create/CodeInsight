#include <stdio.h>
#include <string.h>

int main(){
	char x[1001];
	int num;
	bool f=0;
	while (1){
		scanf("%s", x);
		if (x[0]=='0') break;
		int sum = 0;
		for (int i = 0; i < strlen(x); i++){
			num = x[i] - '0';
			sum += num;
		}
		printf("%d\n",sum);
	}
}