#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	double r, S, L;
	cin >> r;
	S = r * r * 3.141592653589;
	L = r * 2 * 3.141592653589;
	
	printf("%f %f\n", S, L);
	
	return 0;
}