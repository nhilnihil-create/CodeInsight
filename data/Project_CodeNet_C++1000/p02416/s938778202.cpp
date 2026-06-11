#include <cstdio>

int main()
{
	char number[1001];
	int integer, sum;

	while(1){
		sum = 0;

		scanf("%s", number);

		for(int i = 0; number[i] != '\0'; i++){
			integer = number[i] - '0';
			sum += integer;
		}

		if(sum == 0) break;

		printf("%d\n", sum);
	}
	return 0;
}