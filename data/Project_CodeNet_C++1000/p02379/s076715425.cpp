#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	double x1, y1, x2, y2;

	cin >> x1 >> y1 >> x2 >> y2;

	

	double sum = hypot(x2-x1,y2-y1);

	printf("%lf\n",sum);

	return 0;
}