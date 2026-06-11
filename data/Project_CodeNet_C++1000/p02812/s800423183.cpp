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

	int cnt = 0;
	for (int i = 0; i < n - 2; i++)
	{
		if (str[i] == 'A' && str[i + 1] == 'B' && str[i + 2] == 'C')
		{
			cnt++;
			i += 2;
		}
	}

	cout << cnt;
}