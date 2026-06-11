#include <stdio.h>
#include <string.h>

int main(void) {
	char s[100], p[100], cmp[100];
	bool frag = false;
	int lens, lenp;
	scanf("%s\n%s", &s, &p);
	lens = strlen(s);
	lenp = strlen(p);
	for (int i = 0; i < lens; i++) {
		for (int j = 0; j < lenp; j++) {
			cmp[j] = s[(i + j) % lens];
		}
		cmp[lenp] = '\0';
		frag = !strcmp(cmp, p);
		if (frag) { 
			//printf("%s:%s", cmp, p);
			break; }
	}

	if (frag) printf("Yes\n");
	else printf("No\n");
	return 0;
}