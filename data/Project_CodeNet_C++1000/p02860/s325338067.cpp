#include <stdio.h>

int main () {
	int n, ctr = 0, i = 0;
	scanf("%d", &n);
	char str[n];
	scanf("%s", str);
	
	for (int j = n / 2 ; j < n ; j++) {
		if (n % 2 != 0) {
			ctr++;
			break;
		} 
		else if (str[i] == str[j]) {
			i++;
		} else {
			ctr++;
			break;
		} 
	}
	ctr != 0 ? puts("No") : puts("Yes");
	
	return 0;
}