#include <stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int a, b, i, j;
	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0) { break; }
		else {
			for (i = 1;i <= b;i++) { printf("#"); }
			printf("\n");
			for (j = 2;j <= a-1;j++) {
				printf("#");
				{ for (i = 2;i <= b-1;i++) { printf("."); }
				printf("#\n");
				}
			}
			for (i = 1;i <= b;i++) { printf("#"); }
			printf("\n");
			printf("\n");
		}
	}
		return 0;
	
}
