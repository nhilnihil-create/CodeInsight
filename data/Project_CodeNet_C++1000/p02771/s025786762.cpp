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
	int a, b, c;
	cin >> a >> b >> c;
	unordered_set<int> niz{ a, b, c };

	if (niz.size() == 2)
		cout << "Yes";
	else cout << "No";
}