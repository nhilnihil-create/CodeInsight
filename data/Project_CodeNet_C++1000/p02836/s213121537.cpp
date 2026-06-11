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
#include <iomanip>
#include <numeric>
#include <map>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int n = str.length();

	int cnt = 0;

	for (int i = 0; i < n / 2; i++)
	{
		if (str[i] != str[n - i - 1])
			cnt++;
	}

	cout << cnt;
}