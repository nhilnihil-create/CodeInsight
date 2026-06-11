#include<cstdio>

using namespace std;
int main(void)
{
	int a[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
	int m,n;
	while(scanf("%d%d",&m,&n))
	{
		if(m == 0 && n == 0) break;
		for(int i = 0;i < m;i++)
		{
			n += a[i];
		}
		switch(n%7)
		{
		case 1:
			printf("Thursday\n");
			break;
		case 2:
			printf("Friday\n");
			break;
		case 3:
			printf("Saturday\n");
			break;
		case 4:
			printf("Sunday\n");
			break;
		case 5:
			printf("Monday\n");
			break;
		case 6:
			printf("Tuesday\n");
			break;
		case 0:
			printf("Wednesday\n");
			break;
		}
	}
	return 0;
}