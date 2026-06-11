#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main(void) {
	char str[1001];
	int len, i, sum;
	while (1) {
		gets(str);
		len = strlen(str);
		for (i = 0, sum = 0; i < len; i++) {
			sum += str[i] - '0';
		}
		if (!sum)
			break;
		cout << sum << endl;
	}
	return 0;
}