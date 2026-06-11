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
	int n;
	cin >> n;

	vector<int> niz(n);

	int cnt = 0, max = 0;
	for (int i = 0; i < n; i++)
		cin >> niz[i];

	bool flag = false;
	for (int i = 0; i < n - 1; i++)
	{
		if (niz[i] >= niz[i + 1])
		{
			cnt++;
			flag = false;
		}
		else flag = true;
		if (cnt > max)
			max = cnt;
		if (flag)
			cnt = 0;
	}

	cout << max;
}