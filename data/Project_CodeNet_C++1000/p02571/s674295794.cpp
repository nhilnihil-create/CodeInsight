#include <stdio.h>
#include <string.h>

int main(){
	char str[1005], ans[1005];
	int store = 0;
	int value = 0, x = 0;
	int flag = 0;
	scanf("%s", str);
	getchar();
	scanf("%s", ans);
	getchar();
	for(int i = 0; i <= strlen(str) - strlen(ans);i++){
		value = 0;
		x = 0;
		for(int j = 0;j < strlen(ans);j++){
			if(ans[j] != str[x + i]){
				value++;
			}
			x++;
		}
		if(value < store || flag == 0){
			store = value;
			flag = 1;
		}
	}
	printf("%d", store);
	return 0;
}