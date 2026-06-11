#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	cout << a / b << " " << a % b << " ";
	cout << fixed;
	cout.precision(5);
	cout << (double)a / (double)b << endl;

	return 0;
}
