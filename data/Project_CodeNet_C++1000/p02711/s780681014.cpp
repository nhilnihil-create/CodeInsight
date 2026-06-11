#include <bits/stdc++.h>

using namespace std;

char s[5];

int main() {
	scanf("%s", s);
	
	int l = strlen(s);
	
	for (int i = 0; i < l; i++) {
		if (s[i] == '7') return 0 * printf("Yes\n");
	}
	
	printf("No\n");
}
