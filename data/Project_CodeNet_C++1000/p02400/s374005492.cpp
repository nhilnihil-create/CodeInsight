#include <iostream>
#include <string>
#include <stddef.h>
#include <stack>
#include <queue>

using namespace std;

int main() {
	double r;
	double s, l;
	cin >> r;
	s = r*r*3.141592653589;
	l = 2 * r*3.141592653589;
	printf("%.8f %.8f", s,l);
	cin >> r;
}