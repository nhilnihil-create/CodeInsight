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
	cin >> n;

	unordered_set<int> niz;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		niz.insert(x);
	}

	if (niz.size() == n)
		cout << "YES";
	else cout << "NO";
}