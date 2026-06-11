#include <stdio.h>
int main (){
	int n, A = 1;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);
	if(n % 2 == 1){
		A = 0;
	}else{
		int temp = (n / 2) + 1;
		for(int i = 0 ; i < n / 2 ;i++){
			if(s[i] != s[i + (n / 2)]){
				A = 0;
				break;
			}
		}
	}
	if(A == 1){
		printf ("Yes");
	}else{
		printf ("No");
	}
	return 0;
}