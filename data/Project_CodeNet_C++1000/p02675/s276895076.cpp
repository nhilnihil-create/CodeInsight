#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	switch (n % 10)
	{
	case 2:
	case 4:
	case 5:
	case 7:
	case 9:
		printf("hon\n");
		break;
	case 0:
	case 1:
	case 6:
	case 8:
		printf("pon\n");
		break;
	case 3:
		printf("bon\n");
		break;
	}
	return 0;
}