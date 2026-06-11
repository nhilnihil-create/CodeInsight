#include <iostream>
#include <cstdio>
#include <cmath>
//#include <iakioi> 
//             0 1  2  3  4  5  6  7  8  9  10 11 12
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if (month[a] == b)puts("1");
	else puts("0");
}