#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <vector>
using namespace std;

#define C

#ifdef C
int main(void) {
	vector<double> ans;
	int n;
	cin >> n;
	while (n > 0)
	{
		vector<double> point(n);
		double ave = 0;
		for (size_t i = 0; i < n; i++)
		{
			cin>>point[i];
			ave += point[i] / n;
		}
		double sd = 0;
		for (auto a : point)
		{
			sd += pow(a - ave, 2) / n;
		}

		ans.push_back(sqrt(sd));


		cin >> n;
	}
	for (auto a : ans)
	{
		cout << fixed << setprecision(12) << a << endl;
	}

	return 0;
}
#endif // C