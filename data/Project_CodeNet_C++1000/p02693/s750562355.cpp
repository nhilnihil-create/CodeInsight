#include <stdio.h>
int main(){
	int kelipatan, batas1, batas2;
	scanf("%d %d %d", &kelipatan, &batas1, &batas2);
	int temp=(batas2/kelipatan);
	if (temp*kelipatan >=batas1){
		printf("OK\n");
	}
	else printf("NG\n");
	return 0;
}