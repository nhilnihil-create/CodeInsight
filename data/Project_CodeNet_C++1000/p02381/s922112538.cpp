#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double n;
	while (1)
	{
		cin >> n;
		double sum = 0;
		double n_va = 0;
		double m;
		if (n == 0)
			break;
		double s[1000] = { 0.0 };

		for(int i=0; i<n; i++)
		{
			cin >> s[i];
			sum += s[i];
		}
		m = sum / n;
		for (int i = 0; i<n; i++)
		{
			n_va += (s[i]-m)*(s[i] - m);
		}

		cout <<fixed<< sqrt(n_va / n )<< endl;
	}

	return 0;
}