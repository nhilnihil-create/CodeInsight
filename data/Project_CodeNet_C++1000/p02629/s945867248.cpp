#include <stdio.h>
#include <string.h>
int main(){
	long long int n;
	int index = 0;
	scanf("%lld" , &n);
	char s[50];
	while(n>0){
		n--;
		s[index]=(char)'a'+n%26;
		n/=26;
		index++;	
	}
	for(int i = index - 1 ; i >= 0 ; i--){
		printf("%c" , s[i]);
	}
	
	
	return 0;
}