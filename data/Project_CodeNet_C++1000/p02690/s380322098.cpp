#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string.h>
#include<iomanip>
using namespace std;

#define PI 3.14159265358979323846264338327950L

int main() {
	int X;

	cin >> X;

	for (int A = -118; A < 120; A++) {
		for (int B = -119; B < 119; B++) {
			long long test = pow(A, 5) - pow(B, 5);
			if (pow(A, 5) - pow(B, 5) == X) {
				cout << A << " " << B << endl;
				return 0;
			}
		}
	}
	return 0;
}