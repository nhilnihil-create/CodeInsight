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
	int n;
	cin >> n;
	string acl = "ACL";
	string ans;

	for (int i = 0; i < n; i++) {
		ans += acl;
	}

	printf("%s", ans.c_str());

	return 0;
}