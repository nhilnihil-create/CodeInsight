#include <stdio.h>

int main() {
	char a[101];
	scanf("%s", a);
	getchar();
	if(a[1] == 'B'){
		a[1] += 16;
		printf("%s", a);
	}else{
		a[1] -= 16;
		printf("%s", a);
	}

  return 0;
}
