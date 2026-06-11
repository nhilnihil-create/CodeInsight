#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>

using namespace std;

int main()
{
	int x;
	cin >> x;
	
	int coins500 = x / 500;
	int rest500 = x % 500;
	int coins5 = rest500 / 5;

	cout << coins500 * 1000 + coins5 * 5 << endl;
}