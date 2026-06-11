#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	const int MAX_N = 1000;
	int n;
	cin >> n;
	int x[MAX_N] = { 0 };
	int y[MAX_N] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	//p=1 ???????????????????????¢
	double md = 0.0;
	for (int i = 0; i < n; i++) {
		md += fabs(x[i] - y[i]);
	}
	
	//p=2 ???????????????????????¢
	double ed = 0.0;
	for (int i = 0; i < n; i++) {
		ed += pow(fabs(x[i] - y[i]), 2);
	}
	ed = sqrt(ed);
	
	//p=3
	double a = 0.0;
	for (int i = 0; i < n; i++) {
		a += pow(fabs(x[i] - y[i]), 3);
	}
	a = pow(a, 1 / 3.0);
	
	//p=INF
	double b = abs(x[0] - y[0]);
	for (int i = 1; i < n; i++) {
		b = max<double>(b, fabs(x[i] - y[i]));
	}

	printf("%.6f\n%.6f\n%.6f\n%.6f\n", md, ed, a, b);

    return 0;
}