#include <cstdio>
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	if (k == 1){
		printf("0\n");
		return 0;
	}
	printf("%d\n", n - k);
}