#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define M_PI 3.141592653589793


int main(void) {

	int i = 0, j, k;
	int sum;
	int alpha[26] = { 0 };
	char temp[27] = "abcdefghijklmnopqrstuvwxyz";

	char str[1200];

	scanf("%[\x01-\xff]", str);
	

	for (i = 0; i < strlen(str); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			alpha[str[i] - 'a']++;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			alpha[(int)str[i] - 'A']++;
		}
	}
	for (i = 0; i < 26; i++) {
		printf("%c : %d\n", temp[i], alpha[i]);
	}

	return 0;

}