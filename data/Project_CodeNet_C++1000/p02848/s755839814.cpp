#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <set>
#include <array>
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

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] + n > 'Z')
			str[i] += n - 26;
		else str[i] += n;
	}

	cout << str;
}