#include <stdio.h>
#include <string.h>
#include <ctype.h>

char u2l(char c);

int main(void) {
	char W[10], T[1000];
	static long long cnt;

	scanf("%s\n", W);

	for (int i = 0; i < strlen(W); i++) {
		W[i] = u2l(W[i]);
	}

	while (true) {
		scanf("%s", T);
		if (!strcmp(T, "END_OF_TEXT")) break;
		
		for (int i = 0; i < strlen(T); i++) {
			T[i] = u2l(T[i]);
		}
		
		if (!strcmp(T, W)) cnt++;
	}
	printf("%lld\n", cnt);
	return 0;
}

char u2l(char c) {
	if (isupper(c)) c = c - 'A' + 'a';
	return c;
}