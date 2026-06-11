#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <map>
#include <cmath>
#define MOD_P 1000000007
#define MOD_Q 998244353
#define PI 3.14159265358979
#define ll long long
using namespace std;

int main()
{
	string s;
	cin >> s;
	if (s[s.size() - 1] == 's') {
		s += "e";
	}
	s += "s";
	printf("%s", s.c_str());

	return 0;
}