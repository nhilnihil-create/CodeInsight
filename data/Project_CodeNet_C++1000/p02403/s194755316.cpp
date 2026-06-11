#include <cstdio>

int main()
{
	int a, b;
	while (1){
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) break;

		for(int i = 0; i < a; i++){

			for(int j = 0; j < b; j++){
				printf("#");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}