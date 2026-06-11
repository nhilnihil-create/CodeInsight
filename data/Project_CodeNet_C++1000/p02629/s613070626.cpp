#include <stdio.h>
#include <string.h>

int main() {
	long long int a;
	
	char ans[255] = {};
		
	scanf("%lld", &a);

	int i = 0;

		while(a > 0) {
			a--;
			ans[i] = 'a' + (a % 26);
			a /= 26;
			i++;
		}
	
	ans[i] = '\0';
	int len = strlen(ans);
	for(len--; len >= 0; len--) {
	
	printf("%c", ans[len]);
	
	}
	
	return 0;
}
