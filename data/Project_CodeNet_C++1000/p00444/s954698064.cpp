#include <iostream>
#include <cstdio>

int main()
{
	int x;
	int i;

	

	while (1) {
		scanf("%d", &x);
		if (x == 0) break; 
		x = 1000 - x;
		i = 0;
			 
	while (x >= 500 ) {
		i++;
		x -= 500;
	}
	while (x >= 100 ) {
		i++;
		x -= 100;
	}
	while (x >= 50 ) {
		i++;
		x -= 50;
	}
	while (x >= 10 ) {
		i++;
		x -= 10;
	}
	while (x >= 5 ) {
		i++;
		x -= 5;
	}
	while (x >= 1 ) {
		i++;
		x -= 1;
	}
	printf("%d\n", i);
	}
	
	return (0);
}