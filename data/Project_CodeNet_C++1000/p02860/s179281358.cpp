#include <stdio.h>
#include <string.h>

int main (){
	int n,flag=1;
	scanf ("%d",&n);
	char s[n+1];
	scanf ("%s",s);
	
	int len = strlen(s);
	
		if (n%2 != 0){
			printf ("No");
		}
	else {
	for (int i=0; i<len/2; i++){
		if (s[i] != s[(n/2)+i]){
			flag=0;
		}
	}
	if (flag==1){
		printf ("Yes");
	}
	else {
		printf ("No");
	}
}
	
	return 0;
}