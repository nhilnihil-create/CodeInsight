#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	int x;
	cin >> x;

	if (x > 399 && x < 600)
		cout << 8;
	else if (x > 599 && x < 800)
		cout << 7;
	else if (x > 799 && x < 1000)
		cout << 6;
	else if (x > 999 && x < 1200)
		cout << 5;
	else if (x > 1199 && x < 1400)
		cout << 4;
	else if (x > 1399 && x < 1600)
		cout << 3;
	else if (x > 1599 && x < 1800)
		cout << 2;
	else cout << 1;

}