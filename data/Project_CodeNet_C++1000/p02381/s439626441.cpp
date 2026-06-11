#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int main()
{
	while (true)
	{
		int n, s[1000];
		double sum = 0;
		cin >> n;

		if (n == 0) {
			break;
		}

		for (int i = 0;i < n;i++) {
			cin >> s[i];
			sum += s[i];
		}

		double ave = sum / n;
		sum = 0;

		for (int i = 0;i < n;i++) {
			sum += pow(s[i] - ave, 2);
		}

		printf("%lf\n", sqrt(sum / n));
	}

    return 0;
}

