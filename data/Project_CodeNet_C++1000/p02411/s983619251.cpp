#include <stdio.h>

int main() {
	int m, f, r;
	char grade;
	while (1)
	{
		scanf("%d %d %d", &m, &f, &r);
		if (m == -1 && f == -1 && r == -1)break;
		if (m == -1 || f == -1)grade = 'F';
		else if (m + f >= 80)grade = 'A';
		else if (m + f >= 65)grade = 'B';
		else if (m + f >= 50)grade = 'C';
		else if (m + f >= 30 && r >= 50)grade = 'C';
		else if (m + f >= 30)grade = 'D';
		else grade = 'F';
		printf("%c\n", grade);
	}
	return 0;
}