#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
#define MAXT 10
#define MOD 1000000007
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	printf("%d", c - (a - b) > 0 ? c - (a - b) : 0);

	return 0;
}
