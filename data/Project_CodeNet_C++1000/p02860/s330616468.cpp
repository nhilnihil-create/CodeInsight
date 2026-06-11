#include<stdio.h>

int main() {
	int a;
  	scanf("%d",&a);
  	char str[a+1];
	scanf("%s",str);
	if(a % 2 == 1){
		puts("No");
	}else{
		int flag = 1;
		for(int i = 0;i<a/2;i++){
			if(str[i] != str[i+a/2]){
				flag = 0;
			}
		}
		if(flag){
			puts("Yes");
		}else{
			puts("No");
		}
	}	
  return 0;
}