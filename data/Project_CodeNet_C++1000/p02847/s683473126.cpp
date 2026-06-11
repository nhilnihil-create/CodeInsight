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
	string str;
	cin >> str;

	if (str == "SUN")
		cout << "7";
	else if (str == "SAT")
		cout << "1";
	else if (str == "FRI")
		cout << "2";
	else if (str == "THU")
		cout << "3";
	else if (str == "WED")
		cout << "4";
	else if (str == "TUE")
		cout << "5";
	else if (str == "MON")
		cout << "6";
}