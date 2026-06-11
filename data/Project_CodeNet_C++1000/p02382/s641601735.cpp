#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;


double Distance[4];

int main() {
	int n;
	int x[101], absxy[101];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		int y;
		cin >> y;
		absxy[i] = abs(x[i] - y);
	}

	for (int p = 0; p < 3; p++) {
		for (int i = 0; i < n; i++) {
			Distance[p] += pow(absxy[i], p + 1);
		}
			Distance[p] = pow(Distance[p], (double)1.0f / (p + 1));
	}
	Distance[3] = absxy[0];
	for (int i = 1; i < n; i++) {
		if (Distance[3] < absxy[i])
			Distance[3] = absxy[i];
	}

	for (int p = 0; p < 4; p++) {
		printf("%f\n", Distance[p]);
	}

	return 0;
}