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
	long long x;
	cin >> x;

	int cnt = 0;
	unsigned long long curr = 100;

	while (curr < x)
	{
		curr += curr/100;
		cnt++;
	}

	cout << cnt;
}