#include<stdio.h>

int main()
{
	int n;
	int ctr[26] = {0}, flag = 1;
	
	scanf("%d", &n);
	
	char str[n + 1];
	
	scanf("%s", &str);
	
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			++ctr[str[i] - 'a'];
		}
	}
	
	if(n % 2 != 0){
		printf("No\n");
		return 0;
	}else{
		for(int i = 0; i < 26; i++){
			if(ctr[i] > 0){
				if(ctr[i] % 2 != 0){
					flag = 0;
				}
			}
		}
	}
	if(flag == 1){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
}