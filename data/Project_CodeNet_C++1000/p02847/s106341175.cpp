#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

int main() {
	string s;
	cin >> s;
	if (s == "SUN") cout << "7";
	if (s == "MON") cout << "6";
	if (s == "TUE") cout << "5";
	if (s == "WED") cout << "4";
	if (s == "THU") cout << "3";
	if (s == "FRI") cout << "2";
	if (s == "SAT") cout << "1";
	cout << endl;
	return 0;
}
