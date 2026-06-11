#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, id;
	double m, a;
	std::vector<int> arr;

	for (;;)
	{
		cin >> n; if(n == 0) break;
		arr.clear(); m = 0; a = 0;

		for (int i = 0; i < n; ++i)
		{
			cin >> id;
			arr.push_back(id);
			m += id;
		}
		m /= n;

		for (int i = 0; i < n; ++i)		
			a += (arr[i] - m)*(arr[i] - m);
		a /= n;

		cout << setprecision(10) << sqrt(a) << endl;
	}
	return 0;
}