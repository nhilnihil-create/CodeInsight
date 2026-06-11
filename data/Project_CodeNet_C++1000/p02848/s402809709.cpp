#include <stdio.h>
#include <string.h>

int main(){
	int number;
	char str[10000];
	scanf("%d",&number);
	int temp = number;
	scanf("%s",&str);
	int len = strlen (str);
	for (int i = 0; i < len; i++){
		temp = number;
		if (str[i] + number > 'Z'){
			int temp2 = 'Z' - str[i]+1;
			temp -=temp2;
			str[i]='A';
		}
		str[i] += temp;
	}
	printf("%s\n",str);
	return 0;
}
