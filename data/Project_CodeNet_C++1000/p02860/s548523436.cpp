#include <stdio.h>

int main() {
	int n, c[27] = {0}, c1[27] = {0};
	scanf ("%d", &n);
	char s[n+1];
	scanf ("%s", &s);
	
	for (int i = 0; i < n/2; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			c[s[i] - 97]++;
		}
	}
	
	for (int i = n / 2; i < n + 1; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			c1[s[i] - 97]++;
		}
	}
	
	int flag = 1;
	for (int i = 0; i <= 26; i++) {
		if (c[i] == c1[i]) {
			//printf ("theres a match at %d\n", i);
			flag = 1;
		}
		else if (c[i] != c1[i]) {
			//printf ("Theres no mactch at %d", i);
			 flag = 0;
			 break;
		}
	}
	//printf ("the flag is %d\n", flag);
	flag == 1 ? printf ("Yes\n") : printf ("No\n");
	return 0;
}