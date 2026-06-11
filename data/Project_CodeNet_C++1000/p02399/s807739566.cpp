#include <iostream>
#include <stdio.h>

using namespace std;
typedef long long int lint;

void answer()
{
	int a, b;
	cin >> a >> b;
	printf("%d %d %lf\n", a / b, a % b, (double)a / b);
}

int main()
{
	answer();
	return 0;
}