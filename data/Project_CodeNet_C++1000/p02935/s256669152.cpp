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

	vector<double> niz(n);

	for (int i = 0; i < n; i++)
		cin >> niz[i];

	sort(niz.begin(), niz.end());

	double ans;
	for (int i = 0; i < n - 1; i++)
	{
		niz[i + 1] = (niz[i] + niz[i + 1]) / 2;
		ans = niz[i + 1];
	}

	cout << ans;
}