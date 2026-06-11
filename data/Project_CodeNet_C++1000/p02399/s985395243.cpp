#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

#define MAX 2
int main(void)
{
	int a,b;
	int ttmp;
	double tmp;

	cin >> a;
	cin >> b;

	ttmp = a/b;
	tmp = (double)a/(double)b;

	printf("%d ", ttmp);
	printf("%d ", a%b);
	printf("%lf\n", tmp);

	return 0;
}

