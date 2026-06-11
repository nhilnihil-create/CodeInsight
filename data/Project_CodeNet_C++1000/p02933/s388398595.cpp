#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <map>
#include <cmath>
#define MOD_P 1000000007
#define ll long long
using namespace std;



int main()
{
	int n;
	string test;
	cin >> n >> test;

	printf("%s", n < 3200 ? "red" : test.c_str());

	return 0;
}