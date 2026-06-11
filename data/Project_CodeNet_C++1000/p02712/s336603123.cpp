#include <stdio.h>
int main() {
	long long int n;
	long long int tes = 0;
	scanf("%lld", &n);
	
	for (int i = 1; i<= n; i++){
		if (i % 3 != 0 && i % 5 != 0){
			tes = tes + i;
			;
		}
	}
	printf("%lld\n", tes);
	return 0;
}