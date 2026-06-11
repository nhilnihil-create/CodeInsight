#include <stdio.h>

int main(){
	int even;
	int odd;
	int ans = 0;
	scanf("%d %d", &even, &odd);
	int ans1 = even * (even - 1)/2;
	int ans2 = odd * (odd - 1)/2;
	
	printf("%d", ans1 + ans2);
	return 0;
}