#include <stdio.h>

int main(void) {
	int n, flg=0;
	int fact[20];
	char buf[256];
		
	for (int i=0; i<20; i++)  fact[i]=0;
	fact[0]=1;
	
	fgets(buf, sizeof(buf), stdin);
	sscanf(buf, "%d", &n);
	
	if (n<1 || n>20) return 1;
	
	
	for (int i=2; i<=n; i++) {
		for (int j=19; j>=0; j--) {
			fact[j] *= i;
			for (int k=0; k<20; k++) {
				if (fact[k]/10 >= 1) {
					fact[k+1] += fact[k]/10;
					fact[k] = fact[k]%10;
				}
			}
		}
	}
	
	for (int i=19; i>=0; i--) {
		if (flg==0 && fact[i]==0)  continue;
		flg=1;
		printf("%d", fact[i]);
	}
	
	printf("\n");
	
	return 0;
}