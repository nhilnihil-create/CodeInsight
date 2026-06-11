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
	int k, a, b;
	cin >> k >> a >> b;

	while (a <= b)
	{
		if (a % k == 0)
		{
			cout << "OK";
			return 0;
		}
		a++;
	}
	cout << "NG";
}