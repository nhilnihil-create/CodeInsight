#include <stdio.h>

int main(){
	int K;
	char a[100] = "ACL";
	
	scanf("%d", &K);
	
	for (int i=0;i<K;i++){
		printf("%s", a);
	}
	
	return 0;
}