#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;


int main()
{
	int n, x[1001], y[1001], p = 0, p1 = 0;
	double p2 = 0, p3 = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n; i++)
		cin >> y[i];
	for (int i = 0; i < n; i++)
	{
		p1 += abs(x[i] - y[i]);
		p2 += pow(x[i] - y[i], 2);
		p3 += pow(abs(x[i] - y[i]), 3);
		p = max(abs(x[i] - y[i]), p);
	}
	printf("%.6f\n", p1*1.0);
    printf("%.6f\n", sqrt(p2));
    printf("%.6f\n", cbrt(p3));
    printf("%.6f\n", p*1.0);
	return 0;
}

