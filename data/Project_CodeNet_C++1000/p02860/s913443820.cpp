#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <map>
using namespace std;

int main()
{
	int n;
	string str;
	cin >> n >> str;

	if (n % 2)
	{
		cout << "No";
		return 0;
	}

	int j = n / 2;

	for (int i = 0; i < n / 2; i++)
	{
		if (str[i] != str[j++])
		{
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";
}