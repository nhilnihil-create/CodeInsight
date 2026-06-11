#include <iostream>
#include<stdio.h>
 
using namespace std;

int main()
{
	int x,y;

	cin >> x;
	cin >> y;

	printf("%d %d %.5lf",x/y,x%y,(double)x/y);

	return 0;
}