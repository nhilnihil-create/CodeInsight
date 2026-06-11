#include <stdio.h>

int main() {
	int a, b, c, ans = 0, i = 0;
	scanf("%d %d %d", &a, &b, &c);

	while(a > 0 ){
		if(ans >= b && ans <= c){
			printf("OK");
			break;
		}else if(ans > c){
			printf("NG");
	 	break;
		}
		i++;
		ans = a * i; 
		}
  return 0;
}