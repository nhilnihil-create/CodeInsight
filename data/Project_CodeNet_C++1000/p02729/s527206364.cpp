#include <stdio.h>
#include <string.h>
#define ll long long int
//n jumlah bola yang even
// m jumlah bola yang odd
//n+m >= 2
int main(){
	int n, m, even = 0;
	scanf("%d %d", &n, &m);
	even = n * (n -1) /2 + m * (m - 1) /2;
	printf("%d\n", even);
	
	return 0;
}