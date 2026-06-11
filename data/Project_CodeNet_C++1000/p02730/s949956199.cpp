#include <bits/stdc++.h>

using namespace std;

char s[1005];

int main() {
	scanf("%s", s);
	
	int l = strlen(s);
	
	bool gg = 0;
	
	for (int i = 0; i < l / 2; i++) {
		if (s[i] != s[l - 1 - i]) gg = 1;
	}
	
	for (int i = 0; i < l / 4; i++) {
		if (s[i] != s[l / 2 - 1 - i]) gg = 1;
	}
	
	if (gg) printf("No\n");
	else printf("Yes\n");
}
