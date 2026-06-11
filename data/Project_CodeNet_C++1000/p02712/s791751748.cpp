#include <stdio.h>

int main () {
	int a;
	int  b,c,d,e;
	long long int g=0;
	scanf ("%d",&a);
	for(int i = 1;i<=a;i++){
		if (i%5==0&&i%3==0) {
			d++;
		} else if (i%3==0) {
			c++;
		}
		else if (i%5==0) {
			e++;
		} else g+=i;
	}
	printf ("%lld",g);
	return 0;
}