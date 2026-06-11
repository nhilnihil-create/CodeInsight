#include <iostream>

using namespace std;

int main()
{
	int n,val, count = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) {

		cin >> val;
		if (i % 2 == 0 || val % 2 == 0)
			 continue;

		count++;
	}
	cout << count;
}
