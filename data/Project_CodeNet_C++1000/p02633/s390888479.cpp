#include <iostream>
#include <cstdio>

using namespace std;

int X;

int main () {
	scanf ("%d", &X);
	for (int i = 1; ; ++i) if (i * X % 360 == 0) { printf ("%d\n", i); return 0; }
	return 0;
}