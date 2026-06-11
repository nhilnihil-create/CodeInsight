

#include <stdio.h>


int main(int argc, char* argv[])
{
	int a, b;
	char temp[10];

	fgets(temp, sizeof(temp), stdin);
	sscanf(temp, "%d %d", &a,&b);

	if (a > b) {
		printf("a > b\n");
	}
	else if (a < b) {
		printf("a < b\n");
	}
	else {
		printf("a == b\n");
	}

	return 0;
}