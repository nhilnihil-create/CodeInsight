#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;


int main()
{
	int n;
	double x[1000], y[1000];
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> x[i];
	for (int j = 0;j < n;j++)
		cin >> y[j];
	double D1 = 0, D2 = 0, D3 = 0, D4 = 0, b;
	for (int k = 0;k < n;k++)
		D1 = D1 + fabs(x[k] - y[k]);
	for (int l = 0;l < n;l++)
		D2 = D2 + pow(x[l] - y[l], 2);
	D2 = sqrt(D2);
	for (int m = 0;m < n;m++)
		D3 = D3 + pow(fabs(x[m] - y[m]), 3);
	D3 = cbrt(D3);
	for (int o = 0;o < n;o++) {
		b= fabs(x[o] - y[o]);
		if (D4 < b)
			D4 = b;
	}
	printf("%.8lf\n", D1);
	printf("%.8lf\n", D2);
	printf("%.8lf\n", D3);
	printf("%.8lf\n", D4);

    return 0;
}
