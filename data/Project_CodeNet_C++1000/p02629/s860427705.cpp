#include<stdio.h>
#include<string.h>

int main()
{
	long long n;
	char pass[26] = {0};
	
	scanf("%lld", &n);
	int i = 0;
	
	--n;
	while(n >= 0){
		pass[i] = (n % 26) + 'a';
		n /= 26;
		++i;
		--n;
	}
	
	int len = strlen(pass);
	
	for(int i = len - 1 ; i >= 0; i--){
		printf("%c", pass[i]);
	}
	puts("");
}