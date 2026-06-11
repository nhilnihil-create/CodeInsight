#include <stdio.h>
#include <string.h>

int main (){
	long long int a;
	scanf("%lld", &a);
	int count = 0;
	char out[255] = {0};
	a--;
	while (a >= 0){
		out[count] = (a % 26) + 'a';
		a /= 26;
		count++;
		a--;
	}
	for(int i = strlen(out)-1; i >= 0; i--){
		printf("%c", out[i]);
	}
	puts("");

	return 0;
}
