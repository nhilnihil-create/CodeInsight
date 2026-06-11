#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;
	cout << a / b << " " << a % b << " ";
	printf("%f\n", (1.0 * a) / b);
	return 0;
}