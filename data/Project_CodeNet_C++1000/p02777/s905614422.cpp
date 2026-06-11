#include <stdio.h>

int main (){
	
	char s[100], t[100], u[100];
	int a,b;
	int x = 0;
	scanf ("%s %s", s, t);
	scanf ("%d %d", &a, &b);
	getchar();
	scanf ("%s", u);
	
	for(int i = 0 ; s[i] != '\0' || t[i] != '\0' ; i++ ){
		if(s[i] != u[i]){
		x = 1;
		break;
		}
	}
	if (x == 0){
		printf ("%d %d\n", a-1, b);
	}
	else {
		printf ("%d %d\n", a , b-1);
	}
	return 0;
}