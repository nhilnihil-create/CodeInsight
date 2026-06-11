#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <string>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	unsigned long long sum = 0;

	for (int i = 1; i <= n; i++)
		if (i % 15 != 0 && i % 3 != 0 && i % 5 != 0)
			sum += i;

	cout << sum;
}