#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <string>
#include <climits>
#include <set>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x % 2 == 0 && x % 3 && x % 5)
		{
			cout << "DENIED";
			return 0;
		}
	}
	cout << "APPROVED";
}