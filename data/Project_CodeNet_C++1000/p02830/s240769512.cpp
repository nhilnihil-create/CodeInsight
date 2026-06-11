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
#include <numeric>
using namespace std;

int main()
{
	int n;
	string s, t;
	cin >> n >> s >> t;

	for (int i = 0; i < n; i++)
		cout << s[i] << t[i];
}