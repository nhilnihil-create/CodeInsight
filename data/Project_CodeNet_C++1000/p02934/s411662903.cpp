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
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> niz(n);

	for (int i = 0; i < n; i++)
		cin >> niz[i];

	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (double)1 / niz[i];
	}

	cout << 1 / sum;
}