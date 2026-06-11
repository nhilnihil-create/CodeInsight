#include <cstdio>
using namespace std;

int main (void)
{
	char data[1001];
	int i, sum;

	while (scanf("%s", data)!=EOF && data[0] != '0'){
		sum = 0;
		for (i=0; data[i] != '\0'; i++)
			sum += data[i] - '0';

		printf("%d\n", sum);
	}
			
	return 0;
}