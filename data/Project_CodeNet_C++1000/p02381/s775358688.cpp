#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

float se(int n, float s[])
{
	float mu_1 = 0.0;
	float mu_2 = 0.0;

	for (int i = 0; i < n; i++) {
		mu_1 += s[i];
		mu_2 += s[i] * s[i];
	}
	mu_1 /= n;
	mu_2 /= n;

	return sqrt(mu_2 - mu_1 * mu_1);
}

int main()
{
	while (1) {
		int n;
		cin >> n;

		if (n == 0) break;

		float s[n];
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}

		printf("%.8f\n", se(n, s));
	}
}