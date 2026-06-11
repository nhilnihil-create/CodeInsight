#include <iostream>
using namespace std;

int main()
{
	long long int n;
	cin >> n;
	cout << n * (n + 1) / 2
		- (n / 3) * (6 + 3 * (n / 3 - 1)) / 2
		- (n / 5) * (10 + 5 * (n / 5 - 1)) / 2
		+ (n / 15) * (30 + 15 * (n / 15 - 1)) / 2 << endl;
	return 0;
}