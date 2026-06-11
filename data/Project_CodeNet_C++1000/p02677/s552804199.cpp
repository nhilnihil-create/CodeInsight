#include <bits/stdc++.h>
using namespace std;

signed main(){
	const double PI = acos(-1);
	double A, B;
	double H, M;
	scanf("%lf%lf", &A, &B);
	scanf("%lf%lf", &H, &M);
	double x = (H * 360 / 12 + M * 360 / 12 / 60) * PI / 180;
	double y = (M * 360 / 60) * PI / 180;
	printf("%.20lf\n", sqrt(A * A + B * B - 2 * A * B * cos(x - y)));
	return 0;
}