#include<bits/stdc++.h>
using namespace std;

#define PI 3.14159265359

double A, B, H, M;
int main(){
	cin >> A >> B >> H >> M;

	double asita = 2 * PI * H / 12.0 + (2.0*PI/12 * M/60);
	double ax = A * cos(asita);
	double ay = A * sin(asita);

	double bsita = 2 * PI * M / 60.0;
	double bx = B * cos(bsita);
	double by = B * sin(bsita);

	double ans = sqrt((ax-bx) * (ax-bx) + (ay-by) * (ay-by));
	printf("%.10f\n", ans);
}