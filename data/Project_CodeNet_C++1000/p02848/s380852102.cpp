#include <stdio.h>

int main () {
	int test;
	scanf("%d", &test);
	char alpha[10000], hasil[10000];
	scanf("%s", &alpha);
	for (int i = 0 ; alpha[i] != '\0' ; i++){
			hasil[i] = alpha[i] + test;
			if(hasil[i] > 'Z'){
				hasil[i]-= 26;
			}
		printf("%c", hasil[i]);
		}
	return 0;
}