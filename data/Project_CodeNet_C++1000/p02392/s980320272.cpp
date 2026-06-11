#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i, j, x, y, z, a, b, c;
	cin >> a >> b >> c;
	if (a < b && a < c && b < c) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
}