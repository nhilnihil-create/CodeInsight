#include <iostream>
#include <stdio.h>
#include <string.h>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main (void)
{
	int a[3],b[3],A,B;
	A = 0;
	B = 0;

	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
		A += a[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> b[i];
		B += b[i];
	}

	if (A <= B)
	{
		cout << B  << endl;
	}
	else if (A > B)
	{
		cout << A << endl;
	}
}