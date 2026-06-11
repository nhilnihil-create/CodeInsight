#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d", &a);
    scanf("%d %d", &b, &c);
    
    for (b==b;b <= c ;b++){
    	if (b % a == 0){
    		printf("OK\n");
    		return 0;
		}
		else {
			continue;
		}
	}
	printf("NG\n");
	return 0;
}
