#include <stdio.h>
int main (){
	int n;
	scanf ("%d", &n);
	int c, r;
	scanf ("%d %d", &c, &r);
	for (int i = c; i <= r; i++){
		if (i % n == 0){
			printf ("OK");
			return 0;
		}else{
		continue;
		}
	}
	printf ("NG");
	return 0;
}