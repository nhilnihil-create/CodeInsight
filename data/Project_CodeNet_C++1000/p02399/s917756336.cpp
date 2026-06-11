#include <cstdio>
#include <iostream>
using namespace std;

int main(void) {
	int a, b, d, r;

	cin >> a >> b;

	printf("%d %d %.8lf\n", a / b, a%b,(double) a / b);
	return 0;
}