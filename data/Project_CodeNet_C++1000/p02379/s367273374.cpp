#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

#define A

#ifdef A
int main(void) {
	double stx, sty, enx, eny;
	cin >> stx >> sty >> enx >> eny;

	printf("%.6lf\n", sqrt(pow(enx - stx, 2) + pow(eny - sty, 2)));


	return 0;
}
#endif // A