#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n;
	double m;
	vector<double> stddev(1001,-1);
	int count = 0;
	while(cin >> n, n != 0)
	{
		double sum = 0;
		double sqerrsum = 0;
		vector<double> s(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
			sum += s[i];
		}
		m = sum / n;
		for (int i = 0; i < n; i++)
		{
			sqerrsum += pow(s[i] - m, 2);
		}
		stddev[count++] = sqrt(sqerrsum / n);
	}
	for (int i = 0; stddev[i] >= 0; i++)
	{
		cout <<  fixed << setprecision(5) << stddev[i] << endl;
	}
}
