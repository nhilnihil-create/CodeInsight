#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

#define PI 3.14159265358979323846264338327950L

int main() {
	int A, B, H, M;
	cin >> A >> B >> H >> M;

	long double rad = PI * 2 * ((long double)H / 12.0 + ((long double)M / 60.0) / 12.0 - (long double)M / 60.0);

	if (rad >= 180) rad = 360 - rad;
	
	long double raq = (long double)(A * A + B * B) - (long double)(2 * A * B) * cos(rad);

	cout << setprecision(10) << sqrt(raq) << endl;
}