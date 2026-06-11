#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;


int main()
{
	double n, a[1000],S,m,A,x;
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0;i < n;i++)
			cin >> a[i];
		S = 0;
		for (int j = 0;j < n;j++)
			S = S + a[j];
		m = S / n;
		A = 0;
		for (int k = 0;k < n;k++)
			A = A + pow(a[k] - m, 2);
		x=sqrt(A / n);
		printf("%.8lf\n", x);

	}
    return 0;
}
