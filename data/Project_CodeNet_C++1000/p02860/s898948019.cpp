#include<stdio.h>
 
int main(){
	int input;
	scanf("%d", &input);
	getchar();

    char s[101];
	scanf("%s", s);

	if(input % 2 == 1){
		puts("No");
		return 0;
	}
	input /= 2;
	for(int i = 0; i < input; i++){
		if(s[i] != s [i + input]){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}