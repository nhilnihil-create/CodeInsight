#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a, b;
	while (cin >> a >> b) {
		int num = a / (2 * b + 1);
		if (a % (2 * b + 1))
			num++;
		cout << num << endl;
	}
}