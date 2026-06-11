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
	int l;
	cin >> l;

	double res = l / 3.0;

	cout << fixed << setprecision(12) << res * res * res;
}