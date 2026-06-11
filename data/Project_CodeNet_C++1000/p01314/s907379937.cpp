#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	while (true) {
		int n;
		cin >> n;

		if (n == 0) {
			break;
		}

		int count = 0;

		for (int i = 1; i <= n / 2; i++) {
			int sum = 0;
			int cur = i;
			while (sum < n) {
				sum += cur;
				cur++;
				if (sum == n) {
					count++;
				}
			}
		}

		cout << count << endl;
	}

	return 0;
}