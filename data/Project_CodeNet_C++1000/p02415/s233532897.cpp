#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main(void) {
	char str[1200], ans[1200];
	int i, len;
	gets(str);
	len = strlen(str);
	for (i = 0; i < len; i++) {
		if (str[i] >= 'a' && str[i] <= 'z')
			ans[i] = str[i] - 'a' + 'A';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			ans[i] = str[i] - 'A' + 'a';
		else
			ans[i] = str[i];
	}
	ans[i] = '\0';
	cout << ans << endl;
	return 0;
}