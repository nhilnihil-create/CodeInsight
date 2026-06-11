#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <string>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	int m1, d1, m2, d2;
	cin >> m1 >> d1 >> m2 >> d2;

	if (m1 == 2 && d1 == 28 || d1 == 31 || d1 == 30 && d2 == 1)
		cout << "1";
	else cout << "0";
}