#include <stdio.h>

int main(){
	int N;
	scanf("%d", &N);
	char s[10000];
	scanf("%s", s);
	
	for(int i = 0; s[i] != '\0'; i++){
		if(s[i] + N > 90){
		s[i] = s[i] + N - 26;
		}else{
			s[i] += N;
		}
	}
	printf("%s", s);
	return 0;
}