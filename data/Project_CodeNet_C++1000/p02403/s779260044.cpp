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
			for (j = 1;j <= a;j++) {
				{ for (i = 1;i <= b;i++) { printf("#"); }
				printf("\n");
				}
			}
			printf("\n");
		}
	}
		return 0;
	
}
