#include<stdio.h>
int main()
{
	int a, b, ans;
	char c;
	while (1)
	{
		scanf("%d %c %d",&a, &c, &b);
		if (c == '+'){
			ans = a + b;
		}
		else if (c == '-'){
			ans = a - b;
		}
		else if (c == '*'){
			ans = a*b;
		}
		else if (c == '/'){
			ans = a / b;

		}
		else if (c == '?'){
			break;
		}
		printf("%d\n", ans);
	}
	return 0;
}