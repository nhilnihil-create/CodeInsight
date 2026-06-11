#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{
		int n, i, j, tmp;
		cin >> n;
		int x[n], y[n], sub[n];
		for (i=0; i<n; i++) cin >> x[i];
		for (i=0; i<n; i++) cin >> y[i];
		double d1=0, d2, d3, dinf;

		for (i=0; i<n; i++) d1+=(abs(x[i]-y[i]));
		for (i=0; i<n; i++) d2+=(abs((x[i]-y[i])*(x[i]-y[i])));
		d2 = sqrt(d2);
		for (i=0; i<n; i++) d3+=(abs((x[i]-y[i])*(x[i]-y[i])*(x[i]-y[i])));
		d3 = cbrt(d3);
		for (i=0; i<n; i++) {
				tmp = abs(x[i]-y[i]);
				if (dinf < tmp) dinf = tmp;
		}

		cout << fixed << d1 << "\n";
		cout << fixed << d2 << "\n";
		cout << fixed << d3 << "\n";
		cout << fixed << dinf << "\n";
}