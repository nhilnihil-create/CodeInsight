#include <stdio.h>
int main() {
	char str1[105]; // 100 karakter
	char str2[105]; // 100 karakter
	scanf("%s %s", &str1, &str2); // jessica (str1), priscilla (str2)
	printf("%s%s\n", str2, str1);
	return 0;
}