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

	while (n)
	{
		int t = n % 10;
		if (t == 7)
		{
			cout << "Yes";
			return 0;
		}
		n /= 10;
	}
	cout << "No";
}