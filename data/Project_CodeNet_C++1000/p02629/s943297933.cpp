#include <stdio.h>
#include <string.h>
int main() {
	long long int n;
	scanf("%lld", &n);
	char name[20+1] = {0};
	int i = 0;
	n--;
	while (n >= 0)
	{
		name[i] = n % 26 + 'a';
		n /= 26;
		i++;
		n--;				
	}
	int len = strlen(name);
	for(int j = len - 1; j >= 0; j--)
	{
		printf("%c", name[j]);
	}	
	return 0;
}