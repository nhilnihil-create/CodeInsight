#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	string ans;
	ostringstream os;

	while (true)
	{
		int n;
		cin >> n;

		if (n == 0)
			break;

		double sum = 0, squ = 0;
		for (int i = 0; i < n; ++i)
		{
			double num;
			cin >> num;
			sum += num;
			squ += pow(num, 2);
		}

		squ -= (pow(sum, 2) / n);
		double sd = sqrt(squ / n);

		os << setprecision(16) << sd << "\n";
	}

	cout << os.str() << endl;

	return 0;
}