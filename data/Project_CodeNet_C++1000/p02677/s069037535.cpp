#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(void) {
	int A, B, H, M;
	scanf("%d %d %d %d", &A, &B, &H, &M);
	const double PI = 4 * atan(1);

	double rad = 2 * PI * (H / 12. + M / 60. / 12. - M / 60.);
	// cout << beta / PI << " " << alpha / PI << endl;
	printf("%.15lf", sqrt(A*A + B*B - 2*A*B*cos(rad)));

	return 0;
}
