#include <iostream>

using namespace std;

int main()
{
	long long a;
	double b;
	cin >> a >> b;
	cout << a * ((long long) (b * 100 + 0.5)) / 100 << endl;
	return 0;
}